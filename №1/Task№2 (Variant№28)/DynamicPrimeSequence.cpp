#include "DynamicPrimeSequence.h"

void DynamicPrimeSequence::SetUp(DynamicSequence& obj)
{
	if (amountPrimes != 0)
	{
		amountPrimes = 0;
		delete[] primeSequence;
	}
	else { source = obj; }
	primeSequence = new unsigned short[source.GetSize()];
	sieveOfEratosthenes.SetAll(source.GetMaxNum());

	FindingPrimeNumbers();
}
bool DynamicPrimeSequence::TryShow()
{
	if (amountPrimes == 0) { return false; }
	printf("[\n");
	for (int i = 0; i < amountPrimes - 1; i++) { printf("%4i,", primeSequence[i]); }
	printf("%4i\n]\n\n", primeSequence[amountPrimes - 1]);

	return true;
}

void DynamicPrimeSequence::FindingPrimeNumbers()
{
	unsigned short counterFirstIncommingNum = 1;

	//Перебор элементов основного массива
	for (int i = 0; i < source.GetSize(); i++)
	{
		if (IsPrime(source[i]))
		{
			unsigned short indOfLastElInFillable = amountPrimes++; // Индекс последнего простого числа в массиве

			primeSequence[indOfLastElInFillable] = source[i];
			if (indOfLastElInFillable > 1) 
			{
				if (primeSequence[indOfLastElInFillable] == primeSequence[0])
				{
					MovingToBeginning(counterFirstIncommingNum++, indOfLastElInFillable);
					continue;
				}
				Sort(counterFirstIncommingNum, indOfLastElInFillable);
			}
		}
	}
	//Уменьшение размера массива
	ResizePrimeSequence();
}

bool DynamicPrimeSequence::IsPrime(int num)
{
	int actualLengthPrime = sieveOfEratosthenes.amountPrimes; //Действительная длина последовательности простых чисел
	unsigned short* arrayOfPrimes = sieveOfEratosthenes.primesNumber; //Массив, хранящий последовательность простых чисел

	int right = actualLengthPrime - 1; //Правая граница
	int left = 0; //левая граница

	while (true)
	{
		int mid = (right + left) / 2;

		if (num > arrayOfPrimes[mid]) { left = mid + 1; }
		else if (num < arrayOfPrimes[mid]) { right = mid - 1; }
		else { return true; }

		if (left > right) { return false; }
	}
}

void DynamicPrimeSequence::Sort(unsigned short start, unsigned short end)
{
	for (int i = start; i < end; i++)
		if (primeSequence[end] < primeSequence[i]) { std::swap(primeSequence[i], primeSequence[end]); }
}
void DynamicPrimeSequence::MovingToBeginning(unsigned short start, unsigned short end)
{
	for (int j = end; j >= start;)
		std::swap(primeSequence[end--], primeSequence[--j]);
}

void DynamicPrimeSequence::ResizePrimeSequence()
{
	unsigned short* temp = new unsigned short[amountPrimes];

	for (unsigned short i = 0; i < amountPrimes; i++) { temp[i] = primeSequence[i]; }

	delete[] primeSequence;
	primeSequence = temp;
}

unsigned short DynamicPrimeSequence::FindMinEl()
{
	unsigned short minEl = primeSequence[0];
	for (int i = 1; i < amountPrimes; i++)
	{
		if (minEl == primeSequence[i]) { continue; }
		minEl = (minEl < primeSequence[i]) ? minEl : primeSequence[i];
		break;
	}
	return minEl;
}

DynamicPrimeSequence& DynamicPrimeSequence::operator--()
{
	//только если количество элементов больше нуля
	if (amountPrimes <= 0) { printf("Массив пуст!\n"); return*this; }
	
	unsigned short min = FindMinEl();
	unsigned short j = 0; //Счетчик записанных чисел

	for (int i = 0; i < amountPrimes; i++)
	{
		if (primeSequence[i] != min) { primeSequence[j++] = primeSequence[i]; }
	}

	amountPrimes -= amountPrimes - j;
	ResizePrimeSequence();
}
DynamicPrimeSequence::~DynamicPrimeSequence()
{
	if (amountPrimes != 0) { delete[] primeSequence; }
}