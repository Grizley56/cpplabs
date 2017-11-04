#include "PassengersPlane.h"
#include <iostream>
#include <fstream>


PassengersPlane::PassengersPlane(std::string model,
	int year, int passCount, int maxPassCount) : Plane(model, year),
	passengersCount(passCount), maxPassengersCount(maxPassCount)
{
	planeStatistic->addToStatistic(*this);
}

PassengersPlane::PassengersPlane()
{
	passengersCount = 0;
	maxPassengersCount = 300;
}

PassengersPlane::~PassengersPlane()
{
}

int PassengersPlane::GetPassengersCount() const
{
	return passengersCount;
}

void PassengersPlane::SetPassengersCount(int value) const
{
	passengersCount = value;
}

int PassengersPlane::GetMaxPassengersCount() const
{
	return maxPassengersCount;
}

void PassengersPlane::SetMaxPassengersCount(int value)
{
	maxPassengersCount = value;
}

bool PassengersPlane::Fly() const
{
		if (!canFly)
			return false;
	
		std::uniform_int_distribution<> accidentChance(0, 200000);
		std::uniform_int_distribution<> surviveChance(0, 15);
		std::uniform_int_distribution<> surviveCount(1, 25);
	
		if (accidentChance(random) == 0)
		{
			int count = surviveChance(random) == 0 ? surviveCount(random) : 0;
			planeStatistic->fixAccident(GetModel(), count, flyCount);
			canFly = false;
			return false;
		}
		++flyCount;
		return true;
}

double PassengersPlane::FillingRate() const
{
	return ((double)passengersCount / maxPassengersCount) * 100;
}

const char * PassengersPlane::ToString() const
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

	*stringValue += "Passengers " + std::to_string(passengersCount)
			+ " out of " + std::to_string(maxPassengersCount) + '\n';

	double fillingRate = this->FillingRate();

	if (maxPassengersCount)
		*stringValue += "Filling rate: " +  std::to_string(fillingRate)
			.erase(std::to_string(fillingRate).size() - 4) + "%";
	else
		*stringValue += "Filling rate unaviable";

	*stringValue += "\n------------------------------------------";

	return stringValue->c_str();
}

void PassengersPlane::Serialize(const char * path) const
{
	std::ofstream fout(path, std::ios_base::binary);

	if (!fout)
	{
		std::cout << "File " << path << " not found" << std::endl;
		return;
	}

	fout.write((char *)GetYear(), sizeof(GetYear()));
	fout.write((char *)&maxPassengersCount, sizeof(maxPassengersCount));
	fout.write((char *)&passengersCount, sizeof(passengersCount));

	int modelLength = GetModel().length() + 1;
	const char* str = GetModel().c_str() + '\0';

	fout.write((char *)&modelLength, sizeof(int));
	for (size_t i = 0; i < modelLength; i++)
		fout.write((char *)&str[i], sizeof(char));

	for (size_t i = 0; i < MAX_AIRLINES; ++i)
		fout.write((char *)&airlines[i], sizeof(int));

	fout.close();
}

void PassengersPlane::DeSerialize(const char * path)
{
	std::ifstream fin(path, std::ios_base::binary);

	if (!fin)
	{
		std::cout << "File " << path << " not found" << std::endl;
		return;
	}

	int strLen;

	fin.read((char *)this->GetYear(), sizeof(this->GetYear()));
	fin.read((char *)&this->maxPassengersCount, sizeof(this->maxPassengersCount));
	fin.read((char *)&this->passengersCount, sizeof(this->passengersCount));
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

void PassengersPlane::ShowFullStatistic()
{
	planeStatistic->showFull();
}

void PassengersPlane::load(int value)
{
	if (!canFly || passengersCount + value > maxPassengersCount)
	{
		std::cout << "load error" << std::endl;
		return;
	}

	passengersCount += value;
}


PlaneStatistic* PassengersPlane::planeStatistic = new PlaneStatistic();