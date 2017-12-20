#pragma once
#include "Book.h"

struct BookFinder: std::unary_function<Book&, bool>
{
	BookFinder(int from, int to) : _from(from), _to(to) {};
	bool operator()(Book* book) const { return book->getYear() >= _from && book->getYear() <= _to; }
private:
	int _from;
	int _to;
};

