#include "AccidentInfo.h"



AccidentInfo::AccidentInfo()
{
}

AccidentInfo::AccidentInfo(tm * time, int survCount, int flyCount) 
	: time(time), survCount(survCount), flyCount(flyCount) { }


AccidentInfo::~AccidentInfo()
{
}
