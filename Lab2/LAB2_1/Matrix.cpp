#include "Matrix.h"



Matrix::Matrix(size_t rows, size_t columns)
{
	this->rows = rows;
	this->columns = columns;
	arr = new double*[rows];

	for (size_t i = 0; i < rows; ++i)
		*(arr + i) = new double[columns];

	Initialize();
}

Matrix::Matrix(const Matrix& matrix)
{
	this->rows = matrix.rows;
	this->columns = matrix.columns;

	arr = new double*[rows];
	for (size_t i = 0; i < rows; ++i)
		*(arr + i) = new double[columns];

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			*(*(arr + i) + j) = *(*(matrix.arr + i) + j);
}

Matrix::~Matrix()
{
	delete arr;
}

void Matrix::Initialize()
{
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
			arr[i][j] = 0;
}

void Matrix::Display() const
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(4);
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			std::cout << std::setw(10) << At(i, j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
}

Matrix& Matrix::operator++()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			++(*(*(arr + i) + j));
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix matrix(*this);
	(*this)++;
	return matrix;
}


Matrix& Matrix::operator--()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			--(*(*(arr + i) + j));
	return *this;
}

Matrix Matrix::operator--(int)
{
	Matrix matrix(*this);
	(*this)--;
	return matrix;
}


double& Matrix::At(size_t row, size_t column) const
{
	return *(*(arr + row) + column);
}

void Matrix::SetAt(size_t row, size_t column, double& value)
{
	*(*(arr + row) + column) = value;
}