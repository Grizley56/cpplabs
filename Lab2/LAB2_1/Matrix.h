#pragma once
#include <iomanip>
#include <iostream>

class Matrix
{
public:
	Matrix(size_t rows, size_t columns);
	Matrix(const Matrix&);
	~Matrix();

	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);

	double& At(size_t row, size_t column) const;
	void SetAt(size_t row, size_t column, double& value);

	void Display() const;
private:
	void Initialize();

	double** arr;
	size_t rows;
	size_t columns;
};

