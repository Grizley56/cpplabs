#pragma once
#include <iostream>
#include <typeinfo>
#include <exception>
#include <fstream>
#include <string>

template<class T>
class DataManager
{
public:
	DataManager() { };
	~DataManager() { };

	void push(T elem);
	void push(T elem[], size_t count);

	T pop();
	T peek();

private:
	const size_t MAX_COUNT = 64;
	T _data[64];
	size_t _pointer = 0;
	const char* FILE_NAME = "dump.dat";
	std::fstream _fstream;

	void save();
	void load();
};

template <typename T>
void DataManager<T>::push(T elem)
{
	if (_pointer == MAX_COUNT)
	{
		save();
		_pointer = 0;
		_data[_pointer++] = elem;
		return;
	}

	_data[_pointer++] = elem;
}

template <typename T>
void DataManager<T>::push(T elem[], size_t count)
{
	for (size_t i = 0; i < count; ++i)
		push(elem[i]);
}

template <typename T>
T DataManager<T>::pop()
{
	if (_pointer == 0)
		throw std::range_error("empty");

	if (_pointer == 1)
	{
		T elem = _data[--_pointer];
		load();
		return elem;
	}

	T elem = _data[_pointer - 2];
	_data[_pointer - 2] = _data[_pointer - 1];
	--_pointer;

	return elem;
}

template <typename T>
T DataManager<T>::peek()
{
	if(_pointer == 0)
		throw std::range_error("empty");

	return _data[_pointer - 1];
}

template <typename T>
void DataManager<T>::save()
{
	_fstream.open(FILE_NAME, std::ios_base::out | std::ios_base::app | std::ios_base::trunc);
	for (size_t i = 0; i < _pointer; ++i)
		_fstream << _data[i] << ' ';

	_fstream.close();
}

template <typename T>
void DataManager<T>::load()
{
	_fstream.open(FILE_NAME, std::ios_base::in | std::ios_base::out);
	for (size_t i = 0; i < MAX_COUNT; ++i)
		_fstream >> _data[i];

	_fstream.close();
}



template<>
class DataManager<char>
{
public:
	DataManager() { };
	~DataManager() { };

	void push(char elem);
	void push(char elem[], size_t count);
	
	char pop();
	char popLower() { return tolower(pop()); };
	char popUpper() { return toupper(pop()); };
	char peek();

private:
	const size_t MAX_COUNT = 64;
	char _data[64];
	size_t _pointer = 0;
	const char* FILE_NAME = "dump.dat";
	std::fstream _fstream;

	void save();
	void load();
};

void DataManager<char>::push(char elem)
{
	if (elem == '.' || elem == ',' || elem == '!' || elem == ':' || elem == '?' || elem == ';')
		elem = '_';

	if (_pointer == MAX_COUNT)
	{
		save();
		_pointer = 0;
		_data[_pointer++] = elem;
		return;
	}

	_data[_pointer++] = elem;
}

void DataManager<char>::push(char elem[], size_t count)
{
	for (size_t i = 0; i < count; ++i)
		push(elem[i]);
}

char DataManager<char>::pop()
{
	if (_pointer == 0)
		throw std::range_error("empty");

	if (_pointer == 1)
	{
		char elem = _data[--_pointer];
		load();
		return elem;
	}

	char elem = _data[_pointer - 2];
	_data[_pointer - 2] = _data[_pointer - 1];
	--_pointer;

	return elem;
}

char DataManager<char>::peek()
{
	if (_pointer == 0)
		throw std::range_error("empty");

	return _data[_pointer - 1];
}

void DataManager<char>::save()
{
	_fstream.open(FILE_NAME, std::ios_base::out | std::ios_base::app | std::ios_base::trunc);
	for (size_t i = 0; i < _pointer; ++i)
		_fstream << _data[i] << ' ';

	_fstream.close();
}

void DataManager<char>::load()
{
	_fstream.open(FILE_NAME, std::ios_base::in | std::ios_base::out);
	for (size_t i = 0; i < MAX_COUNT; ++i)
		_fstream >> _data[i];

	_fstream.close();
}