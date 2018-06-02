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

void Vector::Input(void) {
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
}

void Vector::Output(void) {
    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\t";

    std::cout << std::endl;
}

int Vector::Sum(void) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int& Vector::operator[](int i) {
    if (i - start < 0 || i - start >= n)
        throw "Index is out of range in Vector::operator[].";
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
    if (n != x.n)
        throw "It is not possible to sum vectors with different sizes.";

    Vector res(n, start);

    for (int i = 0; i < n; i++)
        res.a[i] = a[i] + x.a[i];

    return res;
}

Vector Vector::operator-(const Vector &x) const {
    if (n != x.n)
        throw "Vectors are with different sizes.";

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

std::istream &operator>>(std::istream &is, const Vector &v) {
    for (int i = 0; i < v.n; i++)
        is >> v.a[i];
    return is;
}
