// LAB1_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <iostream>
char* cstrcat(char* dest, const char* src);


int main()
{
	char part1[15]{ 'H', 'E', 'L', 'L', 'O' };
	char part2[10];
	std::scanf("%9s", part2);
	cstrcat(part1, part2);
	std::printf("Result string: %s", part1);
  return 0;
}

char* cstrcat(char* dest, const char* src)
{
	char* pointer = dest + strlen(dest);
	while (*src)
		*pointer++ = *src++;
	return dest;
}

