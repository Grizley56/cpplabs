// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <random>
#include <ctime>

const int SIZE = 20,
					MIN_LIM = 1,
					MAX_LIM = 5;

int processArray(int*, int*, const int);
void DisplayArray(int*, const int);

void bubbleSort(int*, int);

int main()
{
	char word[10];
	char a = getchar();
	std::cout << std::hex << 15;
	int arr1[SIZE] { 0 };
	int arr2[SIZE] { 0 };

	int number = processArray(arr1, arr2, SIZE);

	DisplayArray(arr1, SIZE);
	DisplayArray(arr2, SIZE);
	printf("%s: %d\n", "Least frequent element is", number);
  return 0;
}

int processArray(int* arr1, int* arr2, const int size)
{
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> uid(MIN_LIM, MAX_LIM);
	int elementsCount[5] { 0 };

	for (size_t i = 0; i < size; i++)
	{
		int number = uid(gen);
		arr1[i] = number;
		/*arr2[i] = number;*/
		elementsCount[number-1]++;
	}

	int resultNumber = MAX_LIM;

	/*bubbleSort(arr2, size);

	int prevCounter = 0,
			curCounter = 0;

	for (int i = size-1, tmp = arr2[i]; i >= 0; i--)
	{
		if (arr2[i] != tmp)
		{
			if (!prevCounter || curCounter <= prevCounter)
			{
				resultNumber = arr2[i + 1];
				prevCounter = curCounter;
			}
			curCounter = 0;
		}
		tmp = arr2[i];
		curCounter++;
	}*/

	
	size_t globalIndex = 0;

	for (size_t i = 0; i < MAX_LIM; i++)
	{
		for (size_t j = 0; j < elementsCount[i]; j++)
			arr2[globalIndex++] = i+1;
		if (elementsCount[MAX_LIM-i-1] && elementsCount[MAX_LIM-i-1] <= resultNumber)
			resultNumber = MAX_LIM-i;
	}

	return resultNumber;
}

void DisplayArray(int* arr, const int size)
{
	printf("%c ", '[');
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("%c\n", ']');
}


void bubbleSort(int* arrayPtr, int length_array) 
{
	int temp = 0;
	bool done = false;

	while (!done)
	{
		done = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1])
			{
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				done = false;
			}
	}
}
