#include <iostream>
#include "UserInput.h"

using namespace std;

int main()
{
	system("chcp 1251>nul");

	unsigned short maxLen;
	unsigned short maxNum;

	printf("Введите длину массива: ");
	maxLen = UserInput(0);
	printf("Введите максимально допустимое число: ");
	maxNum = UserInput(0);
	printf("\n\n\n");

	return 0;
}