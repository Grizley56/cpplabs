#include "Subtractor.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

Subtractor::~Subtractor()
{
}

void Subtractor::logToFile(const std::string & filename)
{
	std::ofstream stream(filename, std::ios_base::app | std::ios_base::out);
	ExpressionEvaluator::writeToStream(stream, "minus");
}

void Subtractor::logToScreen()
{
	ExpressionEvaluator::writeToStream(std::cout, "minus");
}

double Subtractor::calculate()
{
	if (opCount == 0)
		return 0;

	double res = operands[0];

	for (size_t i = 1; i < opCount; ++i)
		res -= operands[i];

	return res;
}

void Subtractor::shuffle()
{
	for (size_t i = 1, lastInd = 0; i < opCount; ++i)
	{
		if(operands[i] < 0)
			for(size_t j = lastInd; j < opCount; ++j)
				if (operands[j] >= 0)
				{
					double tmp = operands[i];
					operands[i] = operands[j];
					operands[j] = tmp;
					lastInd = j;
					break;
				}
	}
}

void Subtractor::shuffle(size_t i, size_t j)
{
	if (i > opCount - 1 || j > opCount - 1)
		throw - 1;
	if ( !(operands[i] < 0 && operands[j] >= 0) )
		return;

	double tmp = operands[i];
	operands[i] = operands[j];
	operands[j] = tmp;
}