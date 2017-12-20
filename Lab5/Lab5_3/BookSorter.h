#pragma once
#include <utility>
#include "Book.h"


struct BookSorter: std::unary_function<std::pair<Book&, Book&>, bool>
{
	bool operator()(Book* book1, Book* book2)
	{
		if(book1->getAuthor() != book2->getAuthor())
			return book1->getAuthor() < book2->getAuthor();
		return book1->getName() < book2->getName();
	}
};

