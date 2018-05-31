// Copyright 2018 Shkenev Petr

#include "include/rpn.h"

#include <string>
#include <cstdlib>

#include "include/TStack.h"

int rpn::_Pow(int a, int b) {
    if (b < 0) {
        if (a == 0)  // 1/0
            throw DIVISION_BY_ZERO;

        if (a == 1)  // 1/1
            return 1;

        return 0;  // 1/a < 1
    }

    if (a == 0 && b == 0)  // 0^0
        throw UNDEFINED_OPERATION;

    int res = 1;

    for (int i = 0; i < b; i++)
        res *= a;

    return res;
}

char rpn::_Priority(char a) {
    switch (a) {
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    default: throw INVALID_SYMBOL;
    }
}

int rpn::_Calculate(int num1, int num2, char operation) {
    switch (operation) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;

    case '/':
        if (num2 == 0)
            throw DIVISION_BY_ZERO;
        return num1 / num2;

    case '^': return _Pow(num1, num2);
    default: throw INVALID_OPERATOR;
    }
}

int rpn::calculateRpn(const std::string &s) {
    TStack<int> operandStack(s.length());
    std::string strNum("");
    bool numIsPrepared = false;

    for (size_t i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            strNum += s[i];
            numIsPrepared = true;
        } else {
            if (numIsPrepared) {
                operandStack.Push(std::atoi(strNum.c_str()));
                strNum = "";
                numIsPrepared = false;
            }

            if (s[i] != ' ') {
                int op2 = operandStack.Pop();
                int op1 = operandStack.Pop();
                int res = _Calculate(op1, op2, s[i]);
                operandStack.Push(res);
            }
        }
    }

    if (numIsPrepared)
        operandStack.Push(std::atoi(strNum.c_str()));

    return operandStack.Pop();
}

std::string rpn::convertToRpn(const std::string &s) {
    std::string res("");

    TStack<char> operationStack(s.length() / 2);

    for (size_t i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            res += s[i];
        } else if (s[i] == '(') {
            operationStack.Push(s[i]);
        } else if (s[i] == ')') {
            char op;
            while ((op = operationStack.Pop()) != '(') {
                res += " ";
                res += op;
            }
        } else if (s[i] != ' ') {
            res += " ";

            if (operationStack.isEmpty()) {
                operationStack.Push(s[i]);
            } else if (_Priority(s[i]) > _Priority(operationStack.Peek())) {
                operationStack.Push(s[i]);
            } else {
                while (!operationStack.isEmpty()
                        && operationStack.Peek() != '('
                        && _Priority(operationStack.Peek())
                            >= _Priority(s[i])) {
                    res += operationStack.Pop();
                    res += " ";
                }

                operationStack.Push(s[i]);
            }
        }
    }

    while (!operationStack.isEmpty()) {
        res += " ";
        res += operationStack.Pop();
    }

    return res;
}
