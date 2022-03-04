#include "SieveOfEratosthenes.h"

void SieveOfEratosthenes::SetAll(unsigned short limit)
{
	if (!primesNumber.empty()) primesNumber.clear();

	primesNumber.resize(limit + 1);
	
	FillingSequence();
}

void SieveOfEratosthenes::FillingSequence()
{
	//Заполнение массива
	for (int i = 0; i < primesNumber.size(); i++) { primesNumber.at(i) = i; }

	//Единица не является простым числом, сразу вычеркиваем
	primesNumber.at(1) = 0;

	int sqrtMaxNum = sqrt(primesNumber.size());

	//Фильтрация массива, путем замены всех непростых чисел нулями
	for (int i = 2; i <= sqrtMaxNum; i++)
	{
		if (primesNumber.at(i) != 0)
		{
			for (int j = 2 * i; j < primesNumber.size(); j += i)
			{
				primesNumber.at(j) = 0;
			}
			
		}
	}

	//Удаление всех нулевых элементов из контейнера
	primesNumber.erase(remove(primesNumber.begin(), primesNumber.end(), 0), primesNumber.end());
}