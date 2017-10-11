#include "Vector.h"



Vector::Vector(size_t size)
{
	arr = new double[size];
	this->size = size;
	Initialize();
}

 Vector::Vector(const Vector& vec)
{
	 Vector::Vector(vec.size);
	 for (size_t i = 0; i < size; ++i)
		 *(arr + i) = *(vec.arr + i);
	 
}

Vector::~Vector()
{
	delete arr;
}

void Vector::Initialize()
{
	for (size_t i = 0; i < size; ++i)
		*(arr + i) = 0;
}

void Vector::Display() const
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(4);
	for (size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

Vector& Vector::operator++()
{
	for (size_t i = 0; i < size; i++)
		++(*(arr + i));
	return *this;
}

Vector Vector::operator++(int)
{
	Vector vec(*this);

	(*this)++;

	return vec;
}

Vector& Vector::operator--()
{
	for (size_t i = 0; i < size; i++)
		--(*(arr + i));
	return *this;
}

Vector Vector::operator--(int)
{
	Vector vec(*this);

	(*this)--;

	return vec;
}


double& Vector::operator[](size_t i) const
{
	return *(arr + i);
}

int Vector::GetSize() const
{
	return size;
}
