



#include <vector>
#include "Book.h"
#include <algorithm>
#include <iostream>
#include "BookSorter.h"
#include "BookFinder.h"
#include <functional>

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	std::vector<Book*> books;
	books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
	books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
	books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
	books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
	books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
	books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
	books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
	books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
	books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));


	std::cout << "\nКниги в алфавитном порядке:\n\n";
	BookSorter book_sorter;
	std::sort(books.begin(), books.end(), book_sorter);
	std::vector<Book*>::iterator i;
	for (i = books.begin(); i != books.end(); ++i)
	{
		std::cout << (*i)->getAuthor() << " \""
			<< (*i)->getName() << "\"" << std::endl;
	}

	BookFinder book_finder(2005, 2014);
	std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);

	std::cout << "\nКниги в диапазоне года издания 2005 - 2014:\n\n";

	while (finder != books.end())
	{
	 std::cout << (*finder)->getAuthor() << " \""
		<< (*finder)->getName() << "\"" << std::endl;

		finder = std::find_if(++finder, books.end(), book_finder);
	}

	//////////////
	////TASK 4////
	//////////////
	
	int* years = new int[books.size()];
	for (size_t i = 0; i < books.size(); ++i)
		years[i] = books[i]->getYear();

	int count = std::count_if(years, years + books.size(), std::bind2nd(std::greater<int>(), 2009));
	
	std::cout << "\nКниги вышедшие позже 2009 года:\n\n" << count << std::endl;

	return 0;
}
