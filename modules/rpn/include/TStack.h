// Copyright 2018 Shkenev Petr

#ifndef MODULES_RPN_INCLUDE_TSTACK_H_
#define MODULES_RPN_INCLUDE_TSTACK_H_

#include "messages.h"

template <typename T>
class TStack
{
protected:

    int top; // Индекс последнего добавленного элемента
    int size; // Размер массива
    T *a; // Указатель на массив

public:

    // Конструктор по умолчанию
    TStack(int s = 1)
    {
        top = -1;
        size = s;
        a = new T[s];
    }

    // Конструктор копирования
    TStack(const TStack<T> &x)
    {
        top = x.top;
        size = x.size;

        a = new T[size];
        for (int i = 0; i < size; i++)
            a[i] = x.a[i];
    }

    // Оператор присваивания
    TStack<T>& operator =(const TStack<T> &x)
    {
        top = x.top;

        if (size != x.size)
        {
            size = x.size;
            delete[] a;
            a = new T[size];
        }

        for (int i = 0; i < size; i++)
            a[i] = x.a[i];

        return *this;
    }

    // Деструктор
    ~TStack(void)
    {
    }

    // Добавить элемент на вершину стека
    void Push(T n)
    {
        top++;
        a[top] = n;
    }

    // Извлечь элемент с вершины стека
    T Pop(void)
    {
        if (isEmpty())
            throw POP_EMPTY_STACK;
        return a[top--];
    }

    // Возвращает значение элемента на вершине стека
    T Peek(void) const
    {
        return a[top];
    }

    // Проверка стека на пустоту
    bool isEmpty(void) const
    {
        return top == -1;
    }

    // Проверка стека на переполнение
    bool isFull(void) const
    {
        return top == size - 1;
    }
};

#endif  // MODULES_RPN_INCLUDE_TSTACK_H_
