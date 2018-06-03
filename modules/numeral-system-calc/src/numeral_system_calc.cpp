// Copyright 2018 Yermakov Alexey

#include "include/numeral_system_calc.h"

#include <cstdlib>

#include <stack>
#include <string>

#define INVALID_OPERATOR 1101
#define DIVISION_BY_ZERO 1201

std::string Calc::toString(int number, size_t base) {
    const char *DIGITS = "0123456789ABCDEF";
    char res[34];
    char buf[34];
    char *bufP = buf;
    char *resP = res;

    do {
        unsigned r;
        r = number % base;
        *bufP++ = DIGITS[r];
        number = number / base;
    } while (number != 0);

    do {
        *resP++ = *--bufP;
    } while (bufP != buf);

    *resP = '\0';
    return std::string(res);
}

int Calc::calculate(const std::string &s) {
    return _CalculateRpn(const_cast<char *>(_ConvertToRpn(s).c_str()));
}

char Calc::_Priority(char a) {
    switch (a) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    default: return 0;
    }
}

int Calc::_Calculate(int num1, int num2, char operation) {
    switch (operation) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;

    case '/':
        if (num2 == 0)
            throw DIVISION_BY_ZERO;
        return num1 / num2;

    default: throw INVALID_OPERATOR;
    }
}

int Calc::_CalculateRpn(char *s) {
    std::stack<int> operandStack;
    char *p = s;
    while (*p != '\0') {
        if (*p == '1') {
            operandStack.push(std::strtol(p, &p, 2));
        } else if (*p == '0') {
            if (p[1] == ' ' || p[1] == '\0') {
                operandStack.push(0);
                p++;
            } else {
                p++;
                if (*p == 'x')
                    operandStack.push(std::strtol(++p, &p, 16));
                else
                    operandStack.push(std::strtol(p, &p, 8));
            }
        } else if (*p == ' ') {
            p++;
        } else {
            int op2 = operandStack.top();
            operandStack.pop();
            int op1 = operandStack.top();
            operandStack.pop();
            int res = _Calculate(op1, op2, *p);
            operandStack.push(res);
            p++;
        }
    }

    return operandStack.top();
}

std::string Calc::_ConvertToRpn(const std::string &s) {
    std::string res("");

    std::stack<char> opStack;

    for (size_t i = 0; i < s.length(); i++) {
        if (('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'F')
                || s[i] == 'x') {
            res += s[i];
        } else if (s[i] == '(') {
            opStack.push(s[i]);
        } else if (s[i] == ')') {
            char op;
            while ((op = opStack.top(), opStack.pop(), op) != '(') {
                res += " ";
                res += op;
            }
        } else if (s[i] != ' ') {
            res += " ";

            if (opStack.empty()) {
                opStack.push(s[i]);
            } else if (_Priority(s[i]) > _Priority(opStack.top())) {
                opStack.push(s[i]);
            } else {
                while (!opStack.empty()
                        && opStack.top() != '('
                        && _Priority(opStack.top())
                            >= _Priority(s[i])) {
                    res += opStack.top();
                    opStack.pop();
                    res += " ";
                }

                opStack.push(s[i]);
            }
        }
    }

    while (!opStack.empty()) {
        res += " ";
        res += opStack.top();
        opStack.pop();
    }

    return res;
}
