#include "StaticPrimeSequence.h"

bool StaticPrimeSequence::TryShow()
{
	if (amountPrimes == 0) { return false; }

	printf("[\n");
	for (int i = 0; i < amountPrimes - 1; i++) { printf("%4i,", primeSequence[i]); }
	printf("%4i\n]\n\n", primeSequence[amountPrimes - 1]);

	return true;
}

void StaticPrimeSequence::FillingPrimeSeq(StaticSequence& source)
{
	sieveOfEratosthenes.SetUp(source.GetMaxNum());
	amountPrimes = 0;

	unsigned short repetitionCounter = 1;

	//ѕеребор элементов основного массива
	for (int i = 0; i < source.GetLen(); i++)
	{
		if (IsPrime(source[i]))
		{
			unsigned short indOfLastElInFillable = amountPrimes++; // »ндекс последнего простого числа в массиве

			primeSequence[indOfLastElInFillable] = source[i];
			if (indOfLastElInFillable > 1) 
			{
				if(primeSequence[indOfLastElInFillable] == primeSequence[0])
				{
					MovingToBeginning(repetitionCounter++, indOfLastElInFillable);
					continue;
				}

				Sort(repetitionCounter, indOfLastElInFillable); 
			}
		}
	}
}

bool StaticPrimeSequence::IsPrime(unsigned short num)
{
	int actualLengthPrime = sieveOfEratosthenes.GetAmountPrimes(); //ƒействительна€ длина последовательности простых чисел
	unsigned short* arrayOfPrimes = sieveOfEratosthenes.GetSequence(); //ћассив, хран€щий последовательность простых 

	int right = actualLengthPrime - 1; //ѕрава€ граница
	int left = 0; //лева€ граница

	while (true)
	{
		int mid = (right + left) / 2;

		if (num > arrayOfPrimes[mid]) { left = mid + 1; }
		else if (num < arrayOfPrimes[mid]) { right = mid - 1; }
		else { return true; }

		if (left > right) { return false; }
	}
}

void StaticPrimeSequence::Sort(unsigned short start, unsigned short end)
{
	for (int i = start; i < end; i++)
	{
		if (primeSequence[end] < primeSequence[i]) { std::swap(primeSequence[i], primeSequence[end]); }
	}
}
void StaticPrimeSequence::MovingToBeginning(unsigned short start, unsigned short end)
{
	for (int j = end; j >= start;)
	{
		std::swap(primeSequence[end--], primeSequence[--j]);
	}
}