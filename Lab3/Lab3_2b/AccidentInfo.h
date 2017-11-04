#pragma once
#include <ctime>

struct AccidentInfo
{
	AccidentInfo();
	AccidentInfo(tm* time, int survCount, int flyCount);
	~AccidentInfo();


	tm* time;
	int survCount;
	int flyCount;
};

