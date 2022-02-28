#include "SieveOfEratosthenes.h"

void SieveOfEratosthenes::SetAll(unsigned short limit)
{
	primesNumber.resize(limit + 1);
	
	FillingSequence();
}

void SieveOfEratosthenes::FillingSequence()
{
	//Счетчик вычеркнутых составных чисел
	unsigned short counterStrikeout = 0;

	//Заполнение массива
	for (int i = 0; i < primesNumber.size(); i++)
	{
		primesNumber.at(i) = i;
	}

	//Единица не является простым числом, сразу вычеркиваем
	primesNumber.at(1) = 0;
	counterStrikeout++;

	int sqrtMaxNum = sqrt(primesNumber.size());

	//Фильтрация массива, путем замены всех непростых чисел нулями
	for (int i = 2; i < sqrtMaxNum; i++)
	{
		if (primesNumber.at(i) != 0)
		{
			for (int j = 2 * i; j < primesNumber.size(); j += i)
			{
				if (primesNumber.at(j) != 0)
				{
					primesNumber.at(j) = 0;
					counterStrikeout++;
				}
			}
		}
	}
	primesNumber.resize(primesNumber.size() - ++counterStrikeout);
}