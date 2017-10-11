#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include <cmath>
#include <iomanip>

Vector* Convert2Dto1D(Matrix& matrix, const int rows, const int columns);

Matrix* InitializeMatrix(const int rows, const int columns);


void main()
{
	int rows = 5,
			columns = 3;

	Matrix* matrix = InitializeMatrix(rows, columns);
	matrix->Display();
	Vector* vec = Convert2Dto1D(*matrix, rows, columns);
	vec->Display();

	delete matrix;
	delete vec;
}

Vector* Convert2Dto1D(Matrix& matrix, const int rows, const int columns)
{
	size_t elementCount = rows*columns;
	Vector* vec = new Vector(elementCount);
	size_t ind = 0;
	for (size_t i = 0; i < columns; ++i)
	{
		for (size_t j = 0; j < rows; ++j)
		{
			(*vec)[ind] = matrix.At(j, i);
			++ind;
		}
	}
	return vec;
}

Matrix* InitializeMatrix(const int rows, const int columns)
{
	Matrix* matrix = new Matrix(rows, columns);

	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
		{
			double value = sin(i - j) + cos(i + j);
			matrix->SetAt(i, j, value);
		}
	return matrix;
}
