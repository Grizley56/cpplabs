#include "DataManager.h"
#include <iterator>

int main()
{
	DataManager<int> data;

	int nums[5] = { 0,1,2,3,4 };
	data.push(nums, 5);

	data.push(100);
	data.push(101);
	data.push(102);
	data.push(103);
	data.push(104);

	data.pop();
	data.pop();
	data.pop();
	data.pop();
	data.pop();

	DataManager<char> data2;
	data2.push("Hello", 5);
	data2.push(',');
	data2.push("World", 5);
	for (int i = 0; i < 11; i++)
		std::cout << data2.popLower();
	
}
