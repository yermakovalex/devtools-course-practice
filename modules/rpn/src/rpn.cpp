// Copyright 2018 Shkenev Petr

#include "include/rpn.h"

#include <string>
#include <cstdlib>

#include "include/TStack.h"

#define OPERATORS "+-*/^" // Строка, задающая символы операций

// Возвращает a в степени b
int rpn::_Pow(int a, int b)
{
    if (b < 0)
    {
        if (a == 0) // 1/0
            throw DIVISION_BY_ZERO;

        if (a == 1) // 1/1
            return 1;

        return 0; // 1/a < 1
    }

    if (a == 0 && b == 0) // 0^0
            throw UNDEFINED_OPERATION;

    int res = 1;

    for (int i = 0; i < b; i++)
        res *= a;

    return res;
}

// Определяет, содержится ли символ в строке
bool rpn::_Contains(const std::string &s, char c)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
            return true;
    }

    return false;
}

// Возвращает приоритет оператора
char rpn::_Priority(char a)
{
    switch (a)
    {
    case '(': return 0;
    case ')': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    }
}

// Возвращает результат операции по двум операндам и оператору
int rpn::_Calculate(int num1, int num2, char operation)
{
    switch (operation)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;

    case '/':
        if (num2 == 0)
            throw DIVISION_BY_ZERO;

        return num1 / num2;

    case '^': return _Pow(num1, num2);
    }
}

int rpn::calculateRpn(const std::string &s)
{
    TStack<int> operandStack(s.length()); // Временный стек для операндов
    std::string strNum(""); // Строка для хранения текущего числа
    bool numIsPrepared = false;

    for (size_t i = 0; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9') // цифра
        {
            strNum += s[i];
            numIsPrepared = true;
        }
        else
        {
            if (numIsPrepared) // готовится число для стека
            {
                operandStack.Push(std::atoi(strNum.c_str()));
                strNum = "";
                numIsPrepared = false;
            }

            if (_Contains(OPERATORS, s[i])) // символ оператора
            {
                int op2 = operandStack.Pop();
                int op1 = operandStack.Pop();
                int res = _Calculate(op1, op2, s[i]);
                operandStack.Push(res);
            }
        }
    }

    if (numIsPrepared) // готовится число для стека
        operandStack.Push(std::atoi(strNum.c_str()));

    return operandStack.Pop();

}

std::string rpn::convertToRpn(const std::string &s)
{
    std::string res(""); // Выходная строка с польской записью

    TStack<char> operationStack(s.length() / 2); // Временный стек для операторов

    for (size_t i = 0; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9') // цифра
            res += s[i];
        else if (_Contains(OPERATORS, s[i])) // символ оператора
        {
            res += " "; // Отделить предыдущее число

            if (operationStack.isEmpty())
                operationStack.Push(s[i]);
            else if (_Priority(s[i]) > _Priority(operationStack.Peek()))
                operationStack.Push(s[i]);
            else
            {
                while (!operationStack.isEmpty() && operationStack.Peek() != '(' && _Priority(operationStack.Peek()) >= _Priority(s[i]))
                {
                    res += operationStack.Pop();
                    res += " ";
                }

                operationStack.Push(s[i]);
            }
        }
        else if (s[i] == '(')
            operationStack.Push(s[i]);
        else if (s[i] == ')')
        {
            char op; // Оператор на вершине стека
            while ((op = operationStack.Pop()) != '(')
            {
                res += " ";
                res += op;
            }
        }
    }

    while (!operationStack.isEmpty())
    {
        res += " ";
        res += operationStack.Pop();
    }

    return res;
}
