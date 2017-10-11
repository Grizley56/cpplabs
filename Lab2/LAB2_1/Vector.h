#pragma once
#include <iomanip>
#include <iostream>

class Vector
{
public:
	Vector(size_t);
	Vector(const Vector&);
	~Vector();

	Vector& operator++();
	Vector operator++(int);
	Vector& operator--();
	Vector operator--(int);
	double& operator[](size_t) const;

	int GetSize() const;
	void Display() const;

private:
	void Initialize();

	double* arr;
	int size;	

};

