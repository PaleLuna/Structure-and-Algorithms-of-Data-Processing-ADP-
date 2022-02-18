#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const int MAX_LEN = 50;
const int MAX_NUM = 100;

void AutomaticFilling(int* fillable, int len);
void ShowArray(int* array, int len);
void FindingPrimeNumbers(int* source, int* dump, int len);
void SieveOfEratosthenes(int* fillable, int& amountPrimes);

int main()
{
	system("chcp 1251>nul");

	int source[MAX_LEN];
	int primesInSource[MAX_LEN];

	AutomaticFilling(source, MAX_LEN);
	ShowArray(source, MAX_LEN);

	FindingPrimeNumbers(source, primesInSource, MAX_LEN);

}

void AutomaticFilling(int* fillable, int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		fillable[i] = rand() % MAX_NUM + 1;
}

void ShowArray(int* array, int len)
{
	printf("[\n");
	len--;

	for (int i = 0; i < len; i++)
	{
		printf("%5i,", array[i]);
		if ((i+1) % 10 == 0)
		{
			printf("\n");
		}
	}
	
	printf("%5i\n]\n\n", array[len]);
}

void FindingPrimeNumbers(int* source, int* dump, int len)
{
	int amountPrimes;
	int arrayOfPrimes[MAX_NUM];
	int c = 0;

	SieveOfEratosthenes(arrayOfPrimes, amountPrimes);

	for (int i = 0; i < len; i++)
	{
		int right = amountPrimes - 1;
		int left = 0;
		while (true)
		{
			int mid = (right + left) / 2;

			if (source[i] > arrayOfPrimes[mid]) { left = mid + 1; }
			else if (source[i] < arrayOfPrimes[mid]) { right = mid - 1; }
			else
			{
				dump[c] = source[i];
				if (c > 0)
				{
					for (int j = 1; j <= c; j++)
					{
						for (int k = 0; k < c; k++)
						{
							if (dump[k] > dump[j]) { swap(dump[j], dump[k]); }

						}
					}
				}
				c++;
				break;
			}

			if (left > right) { break; }
		}
	}

	ShowArray(dump, c);


}

void SieveOfEratosthenes(int* fillable, int &amountPrimes)
{
	int tempArr[MAX_NUM + 1];
	int count = 0;

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