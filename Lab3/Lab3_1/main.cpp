#include <iostream>

#include "ExpressionEvaluator.h"
#include "Summator.h"
#include "Subtractor.h"
#include "CustomExpression.h"

int main()
{
	ExpressionEvaluator* expressions[3];

	expressions[0] = new Summator(7);
	double operands[7] { 15, -3.5, 10.5, -2.1, 3.3, 4, 6.3 };
	expressions[0]->setOperands(operands, 7);

	expressions[1] = new CustomExpression(5);
	double operands2[5]{ 15, 10, -3, 12, -6.5 };
	expressions[1]->setOperands(operands2, 5);

	expressions[2] = new Subtractor(3);
	expressions[2]->setOperand(0, 1.5);
	expressions[2]->setOperand(1, 4);
	expressions[2]->setOperand(2, -2.5);

	for (size_t i = 0; i < 3; ++i)
	{
		expressions[i]->logToFile("Lab3.log");
		expressions[i]->logToScreen();
		std::cout << expressions[i]->calculate() << std::endl << std::endl;
	}

	for (size_t i = 0; i < 3; ++i)
	{
		IShuffle* shuffleObject = dynamic_cast<IShuffle*>(expressions[i]);
		if (shuffleObject)
		{
			shuffleObject->shuffle();
			expressions[i]->logToScreen();
			std::cout << "---------------------" << std::endl;
		}
	}

	return 0;
};