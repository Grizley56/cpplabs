#include <string>
#include <map>
#include <fstream>
#include <algorithm>

int main()
{
	std::map<std::string, int> words;
	const size_t SIZE = 2000;

	std::ifstream stream("Three_Comrades.txt");

	while(!stream.eof())
	{
		char text[SIZE];
		stream.getline(text, 2000);

		char* substr = std::strtok(text, ".,:!;? ");

		while (substr != nullptr)
		{
			std::string word = substr;

			if (word.size() > 3)
				words[word]++;

			substr = std::strtok(nullptr, ".,:!;? ");
		}
	}

	return 0;
}

