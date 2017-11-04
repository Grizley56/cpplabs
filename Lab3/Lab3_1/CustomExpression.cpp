#include "CustomExpression.h"
#include <iostream>
#include <fstream>

CustomExpression::~CustomExpression()
{
}

void CustomExpression::logToFile(const std::string & filename)
{
	std::ofstream stream(filename, std::ios_base::app | std::ios_base::out);
	ExpressionEvaluator::writeToStream(stream, "plus");
}

void CustomExpression::logToScreen()
{
	writeToStream(std::cout, "plus");
}

void CustomExpression::writeToStream(std::ostream & stream, const std::string & operation)
{
	stream << "[ -" << opCount << "- operands]" << std::endl;

	Formatting format = SetFormat(stream); //save previous format-style

	for (size_t i = 0; i < opCount; ++i)
	{
		if (operands[i] >= 0)
			stream << operands[i];
		else
			stream << "(" << operands[i] << ")";

		if (i == 0)
			stream << " divide ";
		else if (i < opCount - 1)
			stream << " " + operation + " ";
	}
	stream << std::endl << "[ " << "-RESULT- " << calculate() << " ]" << std::endl;

	Restore(stream, format); //restore format style
}

double CustomExpression::calculate()
{
	if (opCount < 2 || operands[1] == 0)
		return 0;

	double res = operands[0] / operands[1];

	for (size_t i = 2; i < opCount; ++i)
		res += operands[i];

	return res;
}

void CustomExpression::shuffle()
{
	for (size_t i = 1, lastInd = 0; i < opCount; ++i)
	{
		if (operands[i] < 0)
			for (size_t j = lastInd; j < opCount; ++j)
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

void CustomExpression::shuffle(size_t i, size_t j)
{
	if (i > opCount - 1 || j > opCount - 1)
		throw - 1;
	if (!(operands[i] < 0 && operands[j] >= 0))
		return;

	double tmp = operands[i];
	operands[i] = operands[j];
	operands[j] = tmp;
}
