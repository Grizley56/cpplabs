#include <iostream>
#include "Cache.h"

int main()
{
	Cache<int> cache1;
	cache1.put(100);
	cache1.put(12);
	cache1 += 661;
	cache1.put(-20);

	std::cout << cache1.contains(12) << std::endl;
	
	Cache<std::string> cache2;
	cache2.put("Hello");
	cache2 += "World";

	std::cout << cache2.contains("Horde") << std::endl;

	return 0;
}
