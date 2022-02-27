#include <iostream>
#include "SequencePrimeNumbers.h"
#include "UserInput.h"

using namespace std;

int main()
{
	system("chcp 1251>nul");
	
	unsigned short maxLen;
	unsigned short maxNum;

	printf("Введите длину массива: ");
	maxLen = UserInput();
	printf("Введите максимально допустимое число: ");
	maxNum = UserInput();
	printf("\n\n\n");

	SequencePrimeNumbers seqPrimes(maxLen, maxNum);

	printf("Основная последовательность случайных чисел:\n");
	seqPrimes.ShowSource();
	printf("Последовательность простых чисел из основной последовательности:\n");
	seqPrimes.ShowPrimes();

	--seqPrimes;
	seqPrimes.ShowPrimes();


	return 0;
}