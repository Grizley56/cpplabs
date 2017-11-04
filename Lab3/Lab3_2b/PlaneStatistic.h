#pragma once

#include <map>
#include "PlaneInfo.h"

class Plane;

class PlaneStatistic
{
public:
	PlaneStatistic();
	~PlaneStatistic();



private:
	std::map<std::string, PlaneInfo*>* statistic;

public:
	bool addToStatistic(const Plane& plane);
	void fixAccident(const std::string&, int survCount, int flyCount);
	void showFull();
};

