#include "ExpressionEvaluator.h"


ExpressionEvaluator::ExpressionEvaluator(size_t n)
{
	opCount = n;
	operands = new double[opCount] { 0 };
}

ExpressionEvaluator::~ExpressionEvaluator()
{
	delete[] operands;
}

void ExpressionEvaluator::writeToStream(std::ostream & stream, const std::string & operation)
{
	stream << "[ -" << opCount << "- operands]" << std::endl;
	
	Formatting format = SetFormat(stream); //save previous format-style

	for (size_t i = 0; i < opCount; ++i)
	{
		if (operands[i] >= 0)
			stream << operands[i];
		else
			stream << "(" << operands[i] << ")";

		if (i < opCount - 1)
			stream << " " + operation + " ";
	}
	stream << std::endl << "[ " << "-RESULT- " << calculate() << " ]" << std::endl;

	Restore(stream, format); //restore format style
}

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	if (pos > opCount - 1)
		throw - 1;
	operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t elements)
{
	if (elements > opCount)
		throw - 1;
	for (size_t i = 0; i < elements; ++i)
		operands[i] = ops[i];
}

ExpressionEvaluator::Formatting ExpressionEvaluator::SetFormat(std::ostream& stream) const
{
	Formatting formatting;
	formatting.flags = stream.setf(std::ios_base::fixed);
	formatting.precision = stream.precision(2);
	return formatting;
}

void ExpressionEvaluator::Restore(std::ostream& stream, Formatting & formatting) const
{
	stream.setf(formatting.flags, std::ios_base::floatfield);
	stream.precision(formatting.precision);
}
