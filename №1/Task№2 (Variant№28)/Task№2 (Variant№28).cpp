#include <iostream>
#include "FindingPrimeNumbers.h"
#include "RemovingMinimum.h"
#include "UserInput.h"
#include "AutomaticFilling.h"
#include "ShowArray.h"




using namespace std;

int main()
{
	system("chcp 1251>nul");
	
	unsigned short maxLen;
	unsigned short maxNum;

	int amountPrimesInSource;
	unsigned short* source;
	unsigned short* primesInSource;

	printf("Введите длину массива: ");
	maxLen = UserInput();
	printf("Введите максимально допустимое число: ");
	maxNum = UserInput();

	//Инициализация основного массива
	source = new unsigned short[maxLen];
	AutomaticFilling(source, maxLen, maxNum);
	printf("Основной массив натуральных чисел:\n");
	ShowArray(source, maxLen);

	primesInSource = FindingPrimeNumbers(source, maxNum, maxLen, amountPrimesInSource);
	ShowArray(primesInSource, amountPrimesInSource);

	while (true)
	{
		unsigned short choise;
		choise = UserInput();

		if (choise == 1)
		{
			RemovingMinimum(primesInSource, amountPrimesInSource);
			ShowArray(primesInSource, amountPrimesInSource);
		}
		else
		{
			break;
		}
	}


	delete[] source;
	delete[] primesInSource;
	return 0;
}