#include "SequencePrimeNumbers.h"

SequencePrimeNumbers::SequencePrimeNumbers(unsigned short userLen, unsigned short userNum)
{
	sourceLen = userLen;
	maxNum = userNum;

	sieveOfEratosthenes.SetAll(maxNum);

	source = new unsigned short[sourceLen];
	primesInSource = new unsigned short[sourceLen];
	
	SourceFilling();
	FindingPrimeNumbers();
}

void SequencePrimeNumbers::ShowSource()
{
	printf("[\n");
	for (int i = 0; i < sourceLen - 1; i++) { printf("%5i,", source[i]); }
	printf("%5i\n]\n\n", source[sourceLen - 1]);
}
void SequencePrimeNumbers::ShowPrimes()
{
	printf("[\n");
	for (int i = 0; i < amountPrimesInSource - 1; i++) { printf("%5i,", primesInSource[i]); }
	printf("%5i\n]\n\n", primesInSource[amountPrimesInSource - 1]);
}



void SequencePrimeNumbers::SourceFilling()
{
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (int i = 0; i < sourceLen; i++)
		source[i] = rand() % maxNum + 1;
}
void SequencePrimeNumbers::FindingPrimeNumbers()
{
	//ѕоиск совпадений с помощью бинарного поиска
	for (int i = 0; i < sourceLen; i++)
	{
		if (IsPrime(source[i]))
		{
			unsigned short indOfLastElInFillable = amountPrimesInSource++;

			//¬ставка простого числа, не наруша€ возрастающую последовательность
			primesInSource[indOfLastElInFillable] = source[i];
			if (indOfLastElInFillable > 0)
			{
				PrimeSort(indOfLastElInFillable);
			}
		}
		
	}

	primesInSource = arrayCompressor.Compressor(primesInSource, amountPrimesInSource);
}

bool SequencePrimeNumbers::IsPrime(int num)
{
	int actualLengthPrime = sieveOfEratosthenes.amountPrimes; //ƒействительна€ длина последовательности простых чисел
	unsigned short* arrayOfPrimes = sieveOfEratosthenes.primesNumber; //ћассив, хран€щий последовательность простых 

	int right = actualLengthPrime - 1;
	int left = 0;

	while (true)
	{
		int mid = (right + left) / 2;

		if (num > arrayOfPrimes[mid]) { left = mid + 1; }
		else if (num < arrayOfPrimes[mid]) { right = mid - 1; }
		else { return true; }

		if (left > right) { return false; }
	}

}
void SequencePrimeNumbers::PrimeSort(int end)
{
	for (int i = 1; i < end; i++)
	{
			if (primesInSource[end] < primesInSource[i]) { std::swap(primesInSource[i], primesInSource[end]); }
	}
}


SequencePrimeNumbers& SequencePrimeNumbers::operator--()
{
	if (amountPrimesInSource > 1)
	{
		unsigned short* tempArr = new unsigned short[--amountPrimesInSource];

		for (unsigned short i = 0; i < amountPrimesInSource; i++)
		{
			tempArr[i] = primesInSource[i + 1];
		}

		delete[] primesInSource;
		primesInSource = tempArr;
	}

	else
	{
		printf("ƒлина массива слишком мала!");
	}

	return*this;
	
}

SequencePrimeNumbers::~SequencePrimeNumbers()
{
	delete[] source;
	delete[] primesInSource;
}
