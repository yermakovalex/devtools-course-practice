// Copyright 2018 Shkenev Petr

#ifndef MODULES_RPN_INCLUDE_TSTACK_H_
#define MODULES_RPN_INCLUDE_TSTACK_H_

#include "include/messages.h"

template <typename T>
class TStack {
 protected:
    int top;
    int size;
    T *a;

 public:
    explicit TStack(int s = 1) {
        top = -1;
        size = s;
        a = new T[s];
    }

    TStack(const TStack<T> &x) {
        top = x.top;
        size = x.size;

        a = new T[size];
        for (int i = 0; i < size; i++)
            a[i] = x.a[i];
    }

    TStack<T>& operator =(const TStack<T> &x) {
        top = x.top;

        if (size != x.size) {
            size = x.size;
            delete[] a;
            a = new T[size];
        }

        for (int i = 0; i < size; i++)
            a[i] = x.a[i];

        return *this;
    }

    ~TStack(void) {
    }

    void Push(T n) {
        top++;
        a[top] = n;
    }

    T Pop(void) {
        if (isEmpty())
            throw POP_EMPTY_STACK;
        return a[top--];
    }

    T Peek(void) const {
        return a[top];
    }

    bool isEmpty(void) const {
        return top == -1;
    }

    bool isFull(void) const {
        return top == size - 1;
    }
};

#endif  // MODULES_RPN_INCLUDE_TSTACK_H_
