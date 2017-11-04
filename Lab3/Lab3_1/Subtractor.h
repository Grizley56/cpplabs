#pragma once

#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <random>

class Subtractor : public ExpressionEvaluator, public IShuffle
{
public:
	Subtractor(size_t n) : ExpressionEvaluator(n) { };
	~Subtractor();

	void logToFile(const std::string& filename);
	void logToScreen();

	double calculate();

	void shuffle();
	void shuffle(size_t i, size_t j);
};

