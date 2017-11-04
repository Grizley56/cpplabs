#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpression: public ExpressionEvaluator, public IShuffle
{
public:
	CustomExpression(size_t n = 20) : ExpressionEvaluator(n) {};
	~CustomExpression();

	void logToFile(const std::string& filename);
	void logToScreen();
	void writeToStream(std::ostream& stream, const std::string& operation);

	double calculate();

	void shuffle();
	void shuffle(size_t i, size_t j);
};

