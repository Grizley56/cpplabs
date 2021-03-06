#include <iostream>
#include "Plane.h"


Plane::Plane(): flyCount(0), canFly(true), model("none"), year(0)
{
	airlines = new int[MAX_AIRLINES];
	Initialize();
}

Plane::Plane(std::string model, int year) 	
	:model(model), year(year), flyCount(0), canFly(true)
{
	airlines = new int[MAX_AIRLINES];
	Initialize();
}

Plane::~Plane()
{
	delete [] airlines;
}

void Plane::Initialize() const
{
	this->stringValue = new std::string();
	for (size_t i = 0; i < MAX_AIRLINES; i++)
		airlines[i] = -1;
}


std::string Plane::GetModel() const
{
	return model;
}

void Plane::SetModel(const char* value)
{
	model = value;
}

int Plane::GetYear() const
{
	return year;
}

void Plane::SetYear(int value)
{
	year = value;
}

int Plane::GetAirineById(int value) const
{
	if (value < 0 || value > MAX_AIRLINES)
		return -1;

	return airlines[value];
}

bool Plane::RemoveAirlineById(int value) const
{
	if (value < 0 || value > MAX_AIRLINES)
		return false;

	airlines[value] = -1;

	return true;
}

bool Plane::AddAirlane(int value) const
{
	if (value == -1)
		return false;

	for (size_t i = 0; i < MAX_AIRLINES; ++i)
		if (airlines[i] == -1)
		{
			airlines[i] = value;
			return true;
		}

	return false;
}

int * Plane::GetAirlines() const
{
	return airlines;
}

void Plane::ClearAirlines() const
{
	Initialize();
}

const char* Plane::ToString() const
{
	stringValue->clear();

	*stringValue += "Model: " + model + ", Year of issue: " + std::to_string(year) + '\n';
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

	*stringValue += "\n------------------------------------------";

	return stringValue->c_str();
}

void Plane::Serialize() const
{
	std::string filename = model + ".bin";
	Serialize(filename.c_str());
}

void Plane::DeSerialize()
{
	std::string filename = model + ".bin";
	DeSerialize(filename.c_str());
}

void Plane::Serialize(const char * path) const
{
	std::ofstream fout(path, std::ios_base::binary);

	if (!fout)
	{
		std::cout << "File " << path << " not found" << std::endl;
		return;
	}

	fout.write((char *)&year, sizeof(year));

	int modelLength = model.length() + 1;
	const char* str = model.c_str() + '\0';

	fout.write((char *)&modelLength, sizeof(int));
	for (size_t i = 0; i < modelLength; i++)
		fout.write((char *)&str[i], sizeof(char));

	for (size_t i = 0; i < MAX_AIRLINES; ++i)
		fout.write((char *)&airlines[i], sizeof(int));

	fout.close();
}

void Plane::DeSerialize(const char * path)
{
	std::ifstream fin(path, std::ios_base::binary);

	if (!fin)
	{
		std::cout << "File " << path << " not found" << std::endl;
		return;
	}

	int strLen;

	fin.read((char *)&this->year, sizeof(this->year));
	fin.read((char *)&strLen, sizeof(int));

	char* str = new char[strLen];

	for(size_t i = 0; i < strLen; ++i)
		fin.read((char *)&str[i], sizeof(char));

	model = str;
	delete[] str;

	for (size_t i = 0; i < MAX_AIRLINES; ++i)
		fin.read((char *)&airlines[i], sizeof(int));

	std::cout << ToString();

	fin.close();
}


int Plane::Compare(const void * a, const void * b)
{
	if (*((Plane *)a) > *((Plane *)b))  return -1;
	if (*((Plane *)a) == *((Plane *)b)) return 0;
	if (*((Plane *)a) < *((Plane *)b))  return 1;
}

bool Plane::operator>(Plane & val)
{
	return this->FillingRate() > val.FillingRate();
}

bool Plane::operator<(Plane & val)
{
	return this->FillingRate() < val.FillingRate();
}

bool Plane::operator==(Plane & val)
{
	return this->FillingRate() == val.FillingRate();
}

bool Plane::operator<=(Plane & val)
{
	return this->FillingRate() <= val.FillingRate();
}

bool Plane::operator>=(Plane & val)
{
	return this->FillingRate() >= val.FillingRate();
}



std::mt19937 Plane::random(time(0));
