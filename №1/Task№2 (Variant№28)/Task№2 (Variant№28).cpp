#include <iostream>
#include "AutomaticFilling.h"
#include "ShowArray.h"
#include "UserInput.h"
#include "FindingPrimeNumbers.h"


using namespace std;

int main()
{
	system("chcp 1251>nul");
	
	unsigned short userLen;
	int amountPrimesInSource;
	unsigned short* source;
	unsigned short* primesInSource;

	printf("Введите длину массива: ");
	userLen = UserInput();

	//Инициализация основного массива
	source = new unsigned short[userLen];
	AutomaticFilling(source, userLen, 100);
	printf("Основной массив натуральных чисел:\n");
	ShowArray(source, userLen);

	primesInSource = FindingPrimeNumbers(source, 100, userLen, amountPrimesInSource);
	ShowArray(primesInSource, amountPrimesInSource);
}