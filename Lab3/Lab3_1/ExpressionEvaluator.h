#pragma once

#include "ILoggable.h"
#include <iostream>


class ExpressionEvaluator: public ILoggable
{
public:
	ExpressionEvaluator(size_t n = 20);
	virtual ~ExpressionEvaluator();


public:
	virtual void logToFile(const std::string& filename) = 0;
	virtual void logToScreen() = 0;
	virtual void writeToStream(std::ostream& stream, const std::string& operation);

	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);

	virtual double calculate() = 0;

protected:
	struct Formatting 
	{
		std::ios_base::fmtflags flags;
		std::streamsize precision;
	};

	Formatting SetFormat(std::ostream& stream) const;
	void Restore(std::ostream& stream, Formatting& format) const;

	int opCount;
	double* operands;
};

