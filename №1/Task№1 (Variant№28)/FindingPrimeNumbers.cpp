#include "FindingPrimeNumbers.h"

void SieveOfEratosthenes(unsigned short* fillable, unsigned short& amountPrimes);

void FindingPrimeNumbers(int* source, int* fillable, int &amountPrimes)
{
	unsigned short arrayOfPrimes[MAX_NUM];//Массив, хранящий последовательность простых чисел
	unsigned short actualLengthPrime; //Действительная длина последовательности простых чисел
	unsigned short indOfLastElInFillable = 0; //Индекс последнего элемента в заполняемом массиве

	//Генерация последовательности простых чисел
	SieveOfEratosthenes(arrayOfPrimes, actualLengthPrime);

	//Поиск совпадений с помощью бинарного поиска
	for (int i = 0; i < MAX_LEN; i++)
	{
		int right = actualLengthPrime - 1;
		int left = 0;

		while (true)
		{
			int mid = (right + left) / 2;

			if (source[i] > arrayOfPrimes[mid]) { left = mid + 1; }
			else if (source[i] < arrayOfPrimes[mid]) { right = mid - 1; }
			else
			{
				//Вставка простого числа, не нарушая возрастающую последовательность
				fillable[indOfLastElInFillable] = source[i];
				if (indOfLastElInFillable > 0)
				{
					for (int j = 1; j <= indOfLastElInFillable; j++)
					{
						for (int k = 0; k < indOfLastElInFillable; k++)
						{
							if (fillable[k] > fillable[j]) { std::swap(fillable[j], fillable[k]); }
						}
					}
				}

				indOfLastElInFillable++;
				break;
			}

			if (left > right) { break; }
		}
	}

	amountPrimes = indOfLastElInFillable;
}

//Алгоритм "Решето Эратосфена"
void SieveOfEratosthenes(unsigned short* fillable, unsigned short& realLen)
{
	unsigned short tempArr[MAX_NUM + 1]; //Временный массив последовательности чисел от 0 до MAX_NUM включительно
	unsigned short counterOfPrimes = 0;

	//Заполнение массива
	for (int i = 0; i <= MAX_NUM; i++)
	{
		tempArr[i] = i;
	}

	//Единица не является простым числом, сразу вычеркиваем
	tempArr[1] = 0;
	counterOfPrimes++;

	//Фильтрация массива, путем замены всех непростых чисел нулями
	for (int i = 2; i < pow(MAX_NUM, 0.5F); i++)
	{
		if (tempArr[i] != 0)
		{
			for (int j = 2 * i; j <= MAX_NUM; j += i)
			{
				if (tempArr[j] != 0)
				{
					tempArr[j] = 0;
					counterOfPrimes++;
				}
			}
		}
	}

	realLen = MAX_NUM - counterOfPrimes;

	ArrayCleaning(tempArr, fillable, 0);
}