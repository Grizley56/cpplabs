#pragma once
#include <vector>
#include <functional>


template<class T>
class Cache
{
public:
	Cache() { };
	~Cache() { };

	void put(T elem);
	bool contains(T elem);
	Cache& operator+=(const T& elem) { _data.push_back(elem); return *this; }

private:
	std::vector<T> _data;
};

template <class T>
void Cache<T>::put(T elem)
{
	_data.push_back(elem);
}

template <class T>
bool Cache<T>::contains(T elem)
{
	auto it = std::find(_data.begin(), _data.end(), elem);
	if (it != _data.end())
		return true;
	return false;
}





template<>
class Cache<std::string>
{
public:
	Cache() { };
	~Cache() { };

	void put(std::string elem);
	bool contains(std::string elem);
	Cache& operator+=(const std::string& elem) { put(elem); return *this; }

private:
	std::vector<std::string> _data;
};


void Cache<std::string>::put(std::string elem)
{
	if (_data.size() == 100)
		throw std::out_of_range("count is 100");
	_data.push_back(elem);
}

bool Cache<std::string>::contains(std::string elem)
{
	for (auto it = _data.begin(); it != _data.end(); ++it)
		if ((*it)[0] == elem[0]) return true;

	return false;
}