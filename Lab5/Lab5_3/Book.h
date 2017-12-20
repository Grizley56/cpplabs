#pragma once
#include <string>

class Book
{
public:
	Book();
	Book(char* name, char* author, int year) : _name(name), _author(author), _year(year) {};
	~Book();

	std::string getName() const { return _name; }
	std::string getAuthor() const { return _author; }
	int getYear() { return _year; }

private:
	std::string _name;
	std::string _author;
	int _year;
};

