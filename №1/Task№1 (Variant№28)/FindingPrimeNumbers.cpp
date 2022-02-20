#include "FindingPrimeNumbers.h"

void SieveOfEratosthenes(unsigned short* fillable, unsigned short& amountPrimes)
{
	unsigned short tempArr[MAX_NUM + 1];
	unsigned short count = 0;

	for (int i = 0; i <= MAX_NUM; i++)
	{
		tempArr[i] = i;
	}

	tempArr[1] = 0;
	count++;

	for (int i = 2; i < pow(MAX_NUM, 0.5F); i++)
	{
		if (tempArr[i] != 0)
		{
			for (int j = 2 * i; j <= MAX_NUM; j += i)
			{
				if (tempArr[j] != 0)
				{
					tempArr[j] = 0;
					count++;
				}
			}
		}
	}

	amountPrimes = MAX_NUM - count;

	int j = 0;
	for (int i = 0; i <= MAX_NUM; i++)
	{
		if (tempArr[i] != 0)
		{
			fillable[j] = tempArr[i];
			j++;
		}
	}
}

void FindingPrimeNumbers(int* source, int* primesInSource, int len)
{
	unsigned short actualLengthPrime;
	unsigned short arrayOfPrimes[MAX_NUM];

	unsigned short totalAmountPrimes = 0;

	SieveOfEratosthenes(arrayOfPrimes, actualLengthPrime);

	for (int i = 0; i < len; i++)
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
				primesInSource[totalAmountPrimes] = source[i];
				if (totalAmountPrimes > 0)
				{
					for (int j = 1; j <= totalAmountPrimes; j++)
					{
						for (int k = 0; k < totalAmountPrimes; k++)
						{
							if (primesInSource[k] > primesInSource[j]) { std::swap(primesInSource[j], primesInSource[k]); }
						}
					}
				}
				totalAmountPrimes++;
				break;
			}

			if (left > right) { break; }
		}
	}
}