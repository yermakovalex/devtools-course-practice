// Copyright 2018 Yermakov Alexey

#include "include/numeral_system_calc.h"

#include <stack>

#define INVALID_OPERATOR 1101
#define DIVISION_BY_ZERO 1201

std::string Calc::toString(long number, size_t base) {
    const char *DIGITS = "0123456789ABCDEF";
    char res[34];
    char buf[34];
    char *bufP = buf;
    char *resP = res;
    unsigned r;

    if (number < 0) {
        number = -number;
        *resP++ = '-';
    }

    do {
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

long Calc::calculate(const std::string &s) {
    return _CalculateRpn(const_cast<char *>(_ConvertToRpn(s).c_str()));
}

char Calc::_Priority(char a) {
    switch (a) {
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    default: throw INVALID_OPERATOR;
    }
}

long Calc::_Calculate(long num1, long num2, char operation) {
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

long Calc::_CalculateRpn(char *s) {
    std::stack<long> operandStack;
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
            long op2 = operandStack.top();
            operandStack.pop();
            long op1 = operandStack.top();
            operandStack.pop();
            long res = _Calculate(op1, op2, *p);
            operandStack.push(res);
            p++;
        }
    }

    return operandStack.top();
}

std::string Calc::_ConvertToRpn(const std::string &s) {
    std::string res("");

    std::stack<char> operationStack;

    for (size_t i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9' || 'A' <= s[i] && s[i] <= 'F' || s[i] == 'x') {
            res += s[i];
        } else if (s[i] == '(') {
            operationStack.push(s[i]);
        } else if (s[i] == ')') {
            char op;
            while ((op = operationStack.top(), operationStack.pop(), op) != '(') {
                res += " ";
                res += op;
            }
        } else if (s[i] != ' ') {
            res += " ";

            if (operationStack.empty()) {
                operationStack.push(s[i]);
            } else if (_Priority(s[i]) > _Priority(operationStack.top())) {
                operationStack.push(s[i]);
            } else {
                while (!operationStack.empty()
                        && operationStack.top() != '('
                        && _Priority(operationStack.top())
                            >= _Priority(s[i])) {
                    res += operationStack.top();
                    operationStack.pop();
                    res += " ";
                }

                operationStack.push(s[i]);
            }
        }
    }

    while (!operationStack.empty()) {
        res += " ";
        res += operationStack.top();
        operationStack.pop();
    }

    return res;
}
