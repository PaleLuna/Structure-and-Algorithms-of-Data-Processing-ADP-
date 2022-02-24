#include "FindingPrimeNumbers.h"

unsigned short* SieveOfEratosthenes(unsigned short maxNum, int& realLen);

unsigned short* FindingPrimeNumbers(unsigned short* source, unsigned short maxNum, unsigned short maxLen, int& amountPrimes)
{

	int actualLengthPrime; //Действительная длина последовательности простых чисел
	unsigned short* arrayOfPrimes = SieveOfEratosthenes(maxNum, actualLengthPrime);//Массив, хранящий последовательность простых 

	unsigned short* fillable = new unsigned short[maxLen]; //Массив, в который будут записаны простые числа
	unsigned short indOfLastElInFillable = 0; //Индекс последнего элемента в заполняемом массиве


	//Поиск совпадений с помощью бинарного поиска
	for (int i = 0; i < maxLen; i++)
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
	return fillable;
}

//Алгоритм "Решето Эратосфена"
unsigned short* SieveOfEratosthenes(unsigned short maxNum, int& realLen)
{
	unsigned short* tempArr = new unsigned short[maxNum + 1]; //Временный массив последовательности чисел от 0 до MAX_NUM включительно
	unsigned short counterOfPrimes = 0;

	//Заполнение массива
	for (int i = 0; i <= maxNum; i++)
	{
		tempArr[i] = i;
	}

	//Единица не является простым числом, сразу вычеркиваем
	tempArr[1] = 0;
	counterOfPrimes++;

	int sqrtMaxNum = sqrt(maxNum);

	//Фильтрация массива, путем замены всех непростых чисел нулями
	for (int i = 2; i < sqrtMaxNum; i++)
	{
		if (tempArr[i] != 0)
		{
			for (int j = 2 * i; j <= maxNum; j += i)
			{
				if (tempArr[j] != 0)
				{
					tempArr[j] = 0;
					counterOfPrimes++;
				}
			}
		}
	}

	realLen = maxNum - counterOfPrimes;
	CleaningArr(tempArr, maxNum, realLen, 0);

	return tempArr;
}