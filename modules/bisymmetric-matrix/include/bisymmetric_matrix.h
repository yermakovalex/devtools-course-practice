// Copyright 2018 Ioanu Daniel

#ifndef MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_H_
#define MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_H_

#include <iostream>

#include "include/vector.h"

class Matrix {
 private:
    int n;
    Vector *M;

 public:
    explicit Matrix(int size = 1);
    Matrix(const Matrix &x);
    ~Matrix(void);

    void Output(void);
    int GetElem(int row, int col);

    Matrix& operator =(const Matrix &x);
    Matrix operator +(const Matrix &x);
    Matrix operator -(const Matrix &x) const;
    Matrix operator *(int t) const;
    bool operator ==(const Matrix &x) const;

    friend std::istream &operator >> (std::istream &is, const Matrix &m);
};

#endif  // MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_H_
