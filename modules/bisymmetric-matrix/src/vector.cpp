#include "include/vector.h"

// Конструктор по умолчанию
Vector::Vector(int l, int s)
{
	n = l;
	start = s;
	a = new int[l];
}

// Конструктор копирования
Vector::Vector(const Vector &x)
{
	n = x.n;
	start = x.start;

	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = x.a[i];
}

// Деструктор
Vector::~Vector(void)
{
	delete[] a;
}

// Чтение вектора с клавиатуры
void Vector::Input(void)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

// Вывод вектора на экран в одну строку
void Vector::Output(void)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";

	cout << endl;
}

// Сумма элементов вектора
int Vector::Sum(void)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += a[i];

	return sum;
}

// Индексация элементов
int& Vector::operator [](int i)
{
	if (i - start < 0 || i - start >= n)
		throw "Index is out of range in Vector::operator[].";
	return a[i - start];
}

// Оператор присваивания
Vector& Vector::operator =(const Vector &x)
{
	start = x.start;

	if (n != x.n) // необходимо переразмещение
	{
		n = x.n;
		delete[] a;
		a = new int[n];
	}

	for (int i = 0; i < n; i++)
		a[i] = x.a[i];

	return *this;
}

// Сложение векторов
Vector Vector::operator +(const Vector &x) const
{
	if (n != x.n)
		throw "It is not possible to sum vectors with different sizes.";

	Vector res(n, start);

	for (int i = 0; i < n; i++)
		res.a[i] = a[i] + x.a[i];

	return res;
}

// Разность векторов
Vector Vector::operator -(const Vector &x) const
{
	if (n != x.n)
		throw "It is not possible to find the difference of the vectors of different sizes.";

	Vector res(n, start);

	for (int i = 0; i < n; i++)
		res.a[i] = a[i] - x.a[i];

	return res;
}

// Умножение вектора на число
Vector Vector::operator *(int t) const
{
	Vector res(n, start);

	for (int i = 0; i < n; i++)
		res.a[i] = a[i] * t;

	return res;
}

bool Vector::operator !=(const Vector &x)
{
	for (int i = 0; i < n; i++)
		if (a[i] != x.a[i])
			return true;

	return false;
}

std::istream &operator >> (std::istream &is, const Vector &v)
{
	for (int i = 0; i < v.n; i++)
		is >> v.a[i];
	return is;
}