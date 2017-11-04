#include "CargoPlane.h"
#include <iostream>
#include <fstream>


CargoPlane::CargoPlane(std::string model, int year, int cargo, int maxCargo)
	:Plane(model, year), cargo(cargo), maxCargo(maxCargo)
{

}

CargoPlane::CargoPlane()
{
	cargo = 0;
	maxCargo = 15000;
}


CargoPlane::~CargoPlane()
{
}

void CargoPlane::load(int value)
{
	if (cargo + value > maxCargo)
		return;
	cargo += value;
}

bool CargoPlane::Fly() const
{
	++flyCount;
	return true;
}

double CargoPlane::FillingRate() const
{
	return ((double)cargo / maxCargo) * 100;
}

const char * CargoPlane::ToString() const
{
	stringValue->clear();

	*stringValue += "Model: " + GetModel() + ", Year of issue: " +
		std::to_string(GetYear()) + '\n';
	int count = 0;
	std::string airilesString;
	for (size_t i = 0; i < MAX_AIRLINES; ++i)
		if (airlines[i] != -1) {
			++count;
			airilesString += std::to_string(airlines[i]) + ' ';
		}

	if (count > 0)
	{
		*stringValue += "Airiles supported " + std::to_string(count) + ": ";
		*stringValue += airilesString + '\n';
	}
	else
		*stringValue += "Airlines are not supported\n";

	*stringValue += "Total cargo: " + std::to_string(cargo)
		+ " out of " + std::to_string(maxCargo) + '\n';

	double fillingRate = this->FillingRate();

	*stringValue += "Filling rate: " + std::to_string(fillingRate)
	.erase(std::to_string(fillingRate).size() - 4) + "%";

	*stringValue += "\n------------------------------------------";

	return stringValue->c_str();
}

void CargoPlane::Serialize(const char * path) const
{
	std::ofstream fout(path, std::ios_base::binary);

	if (!fout)
	{
		std::cout << "File " << path << " not found" << std::endl;
		return;
	}

	fout.write((char *)GetYear(), sizeof(GetYear()));
	fout.write((char *)&maxCargo, sizeof(maxCargo));
	fout.write((char *)&cargo, sizeof(cargo));

	int modelLength = GetModel().length() + 1;
	const char* str = GetModel().c_str() + '\0';

	fout.write((char *)&modelLength, sizeof(int));
	for (size_t i = 0; i < modelLength; i++)
		fout.write((char *)&str[i], sizeof(char));

	for (size_t i = 0; i < MAX_AIRLINES; ++i)
		fout.write((char *)&airlines[i], sizeof(int));

	fout.close();
}

void CargoPlane::DeSerialize(const char * path)
{
	std::ifstream fin(path, std::ios_base::binary);

	if (!fin)
	{
		std::cout << "File " << path << " not found" << std::endl;
		return;
	}

	int strLen;

	fin.read((char *)this->GetYear(), sizeof(this->GetYear()));
	fin.read((char *)&this->maxCargo, sizeof(this->maxCargo));
	fin.read((char *)&this->cargo, sizeof(this->cargo));
	fin.read((char *)&strLen, sizeof(int));

	char* str = new char[strLen];

	for (size_t i = 0; i < strLen; ++i)
		fin.read((char *)&str[i], sizeof(char));

	SetModel(str);
	delete[] str;

	for (size_t i = 0; i < MAX_AIRLINES; ++i)
		fin.read((char *)&airlines[i], sizeof(int));

	std::cout << ToString();

	fin.close();
}
