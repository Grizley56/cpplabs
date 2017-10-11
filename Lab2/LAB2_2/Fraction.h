#pragma once
#include <string>
class Fraction
{
	public:
		Fraction(int x, int y);
		~Fraction();

		void Reduce();
		std::string ToString();

		Fraction* operator-(Fraction& val);
		Fraction* operator+(Fraction& val);
		Fraction* operator*(Fraction& val);
		Fraction* operator/(Fraction& val);

		static int Counts;
		static int Gcd(int x, int y);
		static void PrintAsFraction(double fraction);
		static void PrintAsFraction(char* fraction);

		

	private:
		int x;
		int y;

		static int Lcm(int x, int y);

};

