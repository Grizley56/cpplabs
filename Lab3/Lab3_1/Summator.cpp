#include "Summator.h"
#include <iostream>
#include <fstream>

Summator::~Summator()
{
}

void Summator::logToFile(const std::string& filename)
{
	std::ofstream stream(filename, std::ios_base::app | std::ios_base::out);
	ExpressionEvaluator::writeToStream(stream, "plus");
}

void Summator::logToScreen()
{
	ExpressionEvaluator::writeToStream(std::cout, "plus");
}

double Summator::calculate()
{
	double res = 0;
	for (size_t i = 0; i < opCount; ++i)
		res += operands[i];
	return res;
}


