#pragma once
#include <iostream>
#include "Fraction.h"
void main()
{
	Fraction* fr = new Fraction(10, 5);
	Fraction* fr2 = new Fraction(33, 5);

	std::cout << "Count: " << Fraction::Counts << std::endl;

	Fraction* fr3 = *fr + *fr2;
	Fraction* fr4 = *fr - *fr2;
	Fraction* fr5 = *fr3 * *fr2;
	Fraction* fr6 = *fr4 / *fr3;

	std::cout << "Count: " << Fraction::Counts << std::endl;

	Fraction::PrintAsFraction("0.23");
	Fraction::PrintAsFraction(12.4);

	fr->Reduce();
	std::cout << fr->ToString() << std::endl;

	delete fr;
	delete fr2;
	delete fr3;
	delete fr4;
	delete fr5;
	delete fr6;
}