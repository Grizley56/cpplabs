#pragma once
#include "Plane.h"
#include "ILoadable.h"
#include "PlaneStatistic.h"


class PassengersPlane: public Plane, public ILoadable
{
public:
	PassengersPlane(std::string, int year, int passCount, int maxPassCount);
	PassengersPlane();
	~PassengersPlane();

	int GetPassengersCount() const;
	void SetPassengersCount(int) const;
	int GetMaxPassengersCount() const;
	void SetMaxPassengersCount(int);

	void load(int);
	bool Fly() const;
	double FillingRate() const;
	const char* ToString() const;

	void Serialize(const char* path) const;
	void DeSerialize(const char* path);

	static void ShowFullStatistic();

private:
	mutable int passengersCount;
	int maxPassengersCount;
	static PlaneStatistic* planeStatistic;
};

