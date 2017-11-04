#pragma once

#include "ExpressionEvaluator.h"


class Summator: public ExpressionEvaluator
{
public:
	Summator(size_t n) : ExpressionEvaluator(n) { };
	~Summator();

	void logToFile(const std::string& filename);
	void logToScreen();

	double calculate();
};

