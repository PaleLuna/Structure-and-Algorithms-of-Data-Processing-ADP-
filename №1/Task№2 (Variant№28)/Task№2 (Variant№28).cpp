#include <iostream>
#include "SequencePrimeNumbers.h"
#include "UserInput.h"

using namespace std;

int main()
{
	system("chcp 1251>nul");
	
	bool repeat = true;

	unsigned short maxLen;
	unsigned short maxNum;

	printf("Введите длину массива: ");
	maxLen = UserInput(0);
	printf("Введите максимально допустимое число: ");
	maxNum = UserInput(0);
	printf("\n\n\n");

	SequencePrimeNumbers seqPrimes(maxLen, maxNum);

	printf("Основная последовательность случайных чисел:\n");
	seqPrimes.ShowSource();
	printf("Последовательность простых чисел из основной последовательности:\n");
	seqPrimes.ShowPrimes();

	unsigned short choise;
	printf("0 - Выход\n");
	printf("1 - Удалить минимальный элемент из последовательности простых чисел\n");
	printf("2 - Вывод последовательности на экран\n");

	do
	{
		printf("Действие№ ");
		choise = UserInput();

		switch (choise)
		{
			case 0:
				repeat = false;
				break;
			case 1:
				--seqPrimes;
				break;
			case 2:
				seqPrimes.ShowPrimes();
			default:
				printf("Действие не определено.\n");
				break;
		}
	} while (repeat);
	return 0;
}