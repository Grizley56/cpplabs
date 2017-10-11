#include "Fraction.h"

#include <iostream>

Fraction::Fraction(int x, int y)
{
	this->x = x;
	this->y = y;

	++Counts;
}

Fraction::~Fraction()
{
}


Fraction* Fraction::operator+(Fraction& fraction)
{
	if (this->y == fraction.y)
		return new Fraction(this->x + fraction.x, this->y);
	
	int lcm = Lcm(this->y, fraction.y);
	int numerator = (this->x * (lcm / this->y)) + (fraction.x * (lcm /fraction.y));
	int denominator = lcm;
	return new Fraction(numerator, denominator);
}
Fraction* Fraction::operator-(Fraction& fraction)
{
	if (this->y == fraction.y)
		return new Fraction(this->x - fraction.x, this->y);

	int lcm = Lcm(this->y, fraction.y);
	int numerator = (this->x * (lcm / this->y)) - (fraction.x * (lcm / fraction.y));
	int denominator = lcm;
	return new Fraction(numerator, denominator);
}
Fraction* Fraction::operator*(Fraction& fraction)
{
	return new Fraction(this->x * fraction.x, this->y * fraction.y);
}
Fraction* Fraction::operator/(Fraction& fraction)
{
	return new Fraction(this->x * fraction.y, this->y * fraction.x);
}


int Fraction::Gcd(int x, int y)
{
	int nod = 1;
	for (int i = (x > y ? y : x); i > 0; i--) 
	{
		if (x % i == 0 && y % i == 0) 
		{
			nod = i;
			break;
		}
	}
	return nod;
}

int Fraction::Lcm(int x, int y)
{
	int gcd = Gcd(x, y);
	return std::abs(x * y) / gcd;
}

void Fraction::Reduce()
{
	int gcd = Gcd(this->x, this->y);
	this->x /= gcd;
	this->y /= gcd;
}

void Fraction::PrintAsFraction(double fraction)
{
	int numerator = (int)(fraction * 100);
	int gcd = Gcd(numerator, 100);
	int denominator = 100 / gcd;
	numerator /= gcd;

	std::cout << numerator << "/" << denominator << std::endl;
}

void Fraction::PrintAsFraction(char* fraction)
{
	bool flag = false;
	int counter = 1;
	char* frc = fraction;
	while (*frc)
	{
		if (flag)
			counter *= 10;

		if (*frc == '.')
			flag = true;

		++frc;
	}

	double number = atof(fraction);
	int numerator = number * counter;
	int denominator = counter;
	
	int gcd = Gcd(numerator, denominator);

	numerator /= gcd;
	denominator /= gcd;

	std::cout << numerator << "/" << denominator << std::endl;
}


int Fraction::Counts = 0;


std::string Fraction::ToString()
{
	std::string str = std::to_string(x) + '/' + std::to_string(y);
	return str;
}