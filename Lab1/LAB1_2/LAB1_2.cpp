// LAB1_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>

double** InitializeArray(const int rows, const int columns);

double* Convert2Dto1D(double** arr, const int rows, const int columns);

void DisplayArray2D(double** arr, const int rows, const int columns);

void DisplayArray1D(const double*, const int);

int main()
{
	int rows = 5,
			columns = 3;

	double** arr2D = InitializeArray(rows, columns);

	double* arr1D = Convert2Dto1D(arr2D, rows, columns);

	DisplayArray2D(arr2D, rows, columns);

	DisplayArray1D(arr1D, rows * columns);

	return 0;
}


double** InitializeArray(const int rows, const int columns)
{
	double** arr = new double*[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new double[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			arr[i][j] = sin(i - j) + cos(i + j);
	return arr;
}


double* Convert2Dto1D(double** arr, const int rows, const int columns)
{
	int elementCount = rows*columns;
	double* newArr = new double[elementCount];
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			*newArr++ = arr[j][i];
		}
	}
	return newArr - elementCount;
}

void DisplayArray2D(double** arr, const int rows, const int columns)
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(4);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << std::setw(10) << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
}

void DisplayArray1D(const double* arr, const int size)
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(4);
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

