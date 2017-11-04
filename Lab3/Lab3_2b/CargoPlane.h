#pragma once
#include "Plane.h"
#include "ILoadable.h"

class CargoPlane: public Plane, public ILoadable
{
public:
	CargoPlane(std::string model, int year, int cargo, int maxCargo);
	CargoPlane();
	~CargoPlane();

	void load(int);
	bool Fly() const;
	double FillingRate() const;
	const char* ToString() const;

	void Serialize(const char* path) const;
	void DeSerialize(const char* path);

private:
	int cargo;
	int maxCargo;
};

