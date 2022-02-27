#include "SieveOfEratosthenes.h"

void SieveOfEratosthenes::SetAll(unsigned short limit)
{
	sequenceLimit = limit;
	primesNumber = new unsigned short[++sequenceLimit];


	FillingSequence();
}

void SieveOfEratosthenes::FillingSequence()
{
	//Счетчик вычеркнутых составных чисел
	unsigned short counterStrikeout = 0;

	//Заполнение массива
	for (int i = 0; i < sequenceLimit; i++)
	{
		primesNumber[i] = i;
	}

	//Единица не является простым числом, сразу вычеркиваем
	primesNumber[1] = 0;
	counterStrikeout++;

	int sqrtMaxNum = sqrt(sequenceLimit);

	//Фильтрация массива, путем замены всех непростых чисел нулями
	for (int i = 2; i < sqrtMaxNum; i++)
	{
		if (primesNumber[i] != 0)
		{
			for (int j = 2 * i; j < sequenceLimit; j += i)
			{
				if (primesNumber[j] != 0)
				{
					primesNumber[j] = 0;
					counterStrikeout++;
				}
			}
		}
	}

	amountPrimes = sequenceLimit - ++counterStrikeout;
	
	primesNumber = arrayCompressor.CleaningArr(primesNumber, sequenceLimit, amountPrimes, 0);
}
