#include "SieveOfEratosthenes.h"

SieveOfEratosthenes::SieveOfEratosthenes()
{
	CreateSequense();
}

unsigned short SieveOfEratosthenes::GetAmountPrimes()
{
	return amountPrimes;
}
unsigned short* SieveOfEratosthenes::GetSequence()
{
	return primeSequence;
}

void SieveOfEratosthenes::CreateSequense()
{
	//Счетчик вычеркнутых составных чисел
	unsigned short counterStrikeout = 0;

	//Заполнение массива
	for (int i = 0; i < MAX_NUM; i++)
	{
		primeSequence[i] = i;
	}

	//Единица не является простым числом, сразу вычеркиваем
	primeSequence[1] = 0;
	counterStrikeout++;

	int sqrtMaxNum = sqrt(MAX_NUM);

	//Фильтрация массива, путем замены всех непростых чисел нулями
	for (int i = 2; i <= sqrtMaxNum; i++)
	{
		if (primeSequence[i] != 0)
		{
			for (int j = 2 * i; j < MAX_NUM; j += i)
			{
				if (primeSequence[j] != 0)
				{
					primeSequence[j] = 0;
					counterStrikeout++;
				}
			}
		}
	}

	amountPrimes = MAX_NUM - ++counterStrikeout;

	ZeroSorting();
}
void SieveOfEratosthenes::ZeroSorting()
{
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (primeSequence[i] == 0)
		{
			int nonZeroElInd = i;
			for (; (nonZeroElInd < MAX_NUM-1) && primeSequence[nonZeroElInd] == 0; nonZeroElInd++);
			std::swap(primeSequence[i], primeSequence[nonZeroElInd]);
		}

	}
}
