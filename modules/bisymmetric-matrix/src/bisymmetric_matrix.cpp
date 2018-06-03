// Copyright 2018 Ioanu Daniel

#include "include/bisymmetric_matrix.h"

Matrix::Matrix(int size) {
    n = size;
    M = new Vector[size];

    for (int i = 0; i <= size / 2; i++)
        M[i] = Vector(i + 1, 1);

    for (int i = static_cast<int>(size / 2) + 1; i < size; i++)
        M[i] = Vector(size - i, 1);
}

Matrix::Matrix(const Matrix &x) {
    n = x.n;
    M = new Vector[n];
    for (int i = 0; i < n; i++)
        M[i] = Vector(x.M[i]);
}

Matrix::~Matrix(void) {
    delete[] M;
}

void Matrix::Output(void) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            std::cout << GetElem(i, j) << "\t";
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int Matrix::GetElem(int row, int col) {
    if (row <= 0 || col <= 0 || row > n || col > n)
        throw "Invalid index in Matrix::GetElem.";

    if (row >= col) {
        if (row + col <= n + 1)
            return M[row - 1][col];
        else
            return M[n + 1 - col - 1][n + 1 - row];
    } else {
        if (row + col <= n + 1)
            return M[col - 1][row];
        else
            return M[n + 1 - row - 1][n + 1 - col];
    }
}

Matrix& Matrix::operator =(const Matrix &x) {
    for (int i = 0; i < n; i++)
        M[i] = x.M[i];

    return *this;
}

Matrix Matrix::operator +(const Matrix &x) {
    if (n != x.n)
        throw "It is not possible to sum matrices with different sizes.";

    Matrix res(n);

    for (int i = 0; i < n; i++)
        res.M[i] = M[i] + x.M[i];

    return res;
}

Matrix Matrix::operator -(const Matrix &x) const {
    if (n != x.n)
        throw "Matrices are with different sizes";

    Matrix res(n);

    for (int i = 0; i < n; i++)
        res.M[i] = M[i] - x.M[i];

    return res;
}

Matrix Matrix::operator *(const int t) const {
    Matrix res(n);

    for (int i = 0; i < n; i++)
        res.M[i] = M[i] * t;

    return res;
}

bool Matrix::operator ==(const Matrix &x) const {
    for (int i = 0; i < n; i++) {
        if (M[i] != x.M[i])
            return false;
    }

    return true;
}

std::istream &operator>>(std::istream &is, const Matrix &m) {
    for (int i = 0; i < m.n; i++)
        is >> m.M[i];

    return is;
}
