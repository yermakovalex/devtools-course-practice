// Copyright 2018 Ioanu Daniel

#include "include/bisymmetric_matrix.h"
#include <stdexcept>

// Конструктор по умолчанию
Matrix::Matrix(int size)
{
	n = size;
	M = new Vector[size];

	// Верхняя часть с растущей длиной векторов
	for (int i = 0; i <= size / 2; i++)
		M[i] = Vector(i + 1, 1);

	// Нижняя часть с убывающей длиной векторов
	for (int i = int(size / 2) + 1; i < size; i++)
		M[i] = Vector(size - i, 1);
}

// Конструктор копирования
Matrix::Matrix(const Matrix &x)
{
	n = x.n;

	M = new Vector[n];
	for (int i = 0; i < n; i++)
		M[i] = x.M[i];
}

// Деструктор
Matrix::~Matrix(void)
{
	delete[] M;
}

// Ввод матрицы
void Matrix::Input(void)
{
	for (int i = 0; i < n; i++)
		M[i].Input();
}

// Вывод матрицы
void Matrix::Output(void)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << GetElem(i, j) << "\t";
		cout << endl;
	}

	cout << endl;
}

// Значение элемента матрицы
int Matrix::GetElem(int row, int col)
{
	if (row <= 0 || col <= 0 || row > n || col > n)
		throw "Invalid index in Matrix::GetElem.";

	if (row >= col) // нижний треугольник
	{
		if (row + col <= n + 1)
			return M[row - 1][col]; // прямой доступ
		else
			return M[n + 1 - col - 1][n + 1 - row];
	}
	else
	{
		if (row + col <= n + 1)
			return M[col - 1][row];
		else
			return M[n + 1 - row - 1][n + 1 - col];

	}
}

// Оператор присваивания
Matrix& Matrix::operator =(const Matrix &x)
{
	if (n != x.n)
	{
		n = x.n;
		delete[] M;
		M = new Vector[n];
	}

	for (int i = 0; i < n; i++)
		M[i] = x.M[i];

	return *this;
}

// Сложение матриц
Matrix Matrix::operator +(const Matrix &x) const
{
	if (n != x.n)
		throw "It is not possible to sum matrices with different sizes.";

	Matrix res(n);

	for (int i = 0; i < n; i++)
		res.M[i] = M[i] + x.M[i];

	return res;
}

// Разность матриц
Matrix Matrix::operator -(const Matrix &x) const
{
	if (n != x.n)
		throw "It is not possible to find the difference of the matrices of different sizes.";

	Matrix res(n);

	for (int i = 0; i < n; i++)
		res.M[i] = M[i] - x.M[i];

	return res;
}

// Умножение матрицы на число
Matrix Matrix::operator *(const int t) const
{
	Matrix res(n);

	for (int i = 0; i < n; i++)
		res.M[i] = M[i] * t;

	return res;
}

std::istream &operator >> (std::istream &is, const Matrix &m)
{
	for (int i = 0; i < n; i++)
		is >> m[i];
}
