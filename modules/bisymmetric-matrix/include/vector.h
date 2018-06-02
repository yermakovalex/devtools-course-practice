// Copyright 2018 Ioanu Daniel

#ifndef MODULES_BISYMMETRIC_MATRIX_INCLUDE_VECTOR_H_
#define MODULES_BISYMMETRIC_MATRIX_INCLUDE_VECTOR_H_

#include <iostream>

class Vector {
 private:
    int *a;
    int n;
    int start;

 public:
    explicit Vector(int l = 1, int s = 1);
    Vector(const Vector &x);
    ~Vector(void);

    int& operator[](int i);
    Vector& operator=(const Vector &x);
    Vector operator+(const Vector &x) const;
    Vector operator-(const Vector &x) const;
    Vector operator*(int t) const;
    bool operator!=(const Vector &x);

    friend std::istream &operator >> (std::istream &is, const Vector &v);
};

#endif  // MODULES_BISYMMETRIC_MATRIX_INCLUDE_VECTOR_H_
