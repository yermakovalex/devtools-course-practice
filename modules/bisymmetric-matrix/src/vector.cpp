// Copyright 2018 Ioanu Daniel

#include "include/vector.h"

Vector::Vector(int l, int s) {
    n = l;
    start = s;
    a = new int[l];
}

Vector::Vector(const Vector &x) {
    n = x.n;
    start = x.start;

    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = x.a[i];
}

Vector::~Vector(void) {
    delete[] a;
}

int& Vector::operator[](int i) {
    return a[i - start];
}

Vector& Vector::operator=(const Vector &x) {
    start = x.start;

    if (n != x.n) {
        n = x.n;
        delete[] a;
        a = new int[n];
    }

    for (int i = 0; i < n; i++)
        a[i] = x.a[i];

    return *this;
}

Vector Vector::operator+(const Vector &x) const {
    Vector res(n, start);

    for (int i = 0; i < n; i++)
        res.a[i] = a[i] + x.a[i];

    return res;
}

Vector Vector::operator-(const Vector &x) const {
    Vector res(n, start);

    for (int i = 0; i < n; i++)
        res.a[i] = a[i] - x.a[i];

    return res;
}

Vector Vector::operator*(int t) const {
    Vector res(n, start);

    for (int i = 0; i < n; i++)
        res.a[i] = a[i] * t;

    return res;
}

bool Vector::operator!=(const Vector &x) {
    for (int i = 0; i < n; i++)
        if (a[i] != x.a[i])
            return true;

    return false;
}

std::istream &operator >> (std::istream &is, const Vector &v) {
    for (int i = 0; i < v.n; i++)
        is >> v.a[i];
    return is;
}
