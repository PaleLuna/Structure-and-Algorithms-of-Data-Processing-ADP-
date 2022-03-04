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
	//Инициадизация генератора случайных чисел
	srand(time(NULL));

	//Заполнение массива случайными числами
	for (int i = 0; i < sourceLen; i++)
		source[i] = rand() % maxNum + 1;
}
void SequencePrimeNumbers::FindingPrimeNumbers()
{
	for (int i = 0; i < sourceLen; i++)
	{
		if (IsPrime(source[i]))
		{
			unsigned short indOfLastElInFillable = amountPrimesInSource++;

			//Вставка простого числа, не нарушая возрастающую последовательность
			primesInSource[indOfLastElInFillable] = source[i];
			if (indOfLastElInFillable > 0) { PrimeSort(indOfLastElInFillable); }
		}
	}

	ResizePrimeSequence();
}
void SequencePrimeNumbers::ResizePrimeSequence()
{
	unsigned short* temp = new unsigned short[amountPrimesInSource];

	for (unsigned short i = 0; i < amountPrimesInSource; i++) { temp[i] = primesInSource[i]; }

	delete[] primesInSource;
	primesInSource = temp;
}

bool SequencePrimeNumbers::IsPrime(int num)
{
	int actualLengthPrime = sieveOfEratosthenes.amountPrimes; //Действительная длина последовательности простых чисел
	unsigned short* arrayOfPrimes = sieveOfEratosthenes.primesNumber; //Массив, хранящий последовательность простых 

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
	for (int i = 0; i < end; i++)
	{
			if (primesInSource[end] < primesInSource[i]) { std::swap(primesInSource[i], primesInSource[end]); }
	}
}

unsigned short SequencePrimeNumbers::СounterMinPrimes()
{
	unsigned short minEl = primesInSource[0];
	unsigned short counter = 1;

	for (int i = 1; i < amountPrimesInSource; i++)
	{
		if (primesInSource[i] == minEl) { counter++; }
		else { break; }
	}
	return counter;
}
SequencePrimeNumbers& SequencePrimeNumbers::operator--()
{
	if (amountPrimesInSource == 0)
	{
		unsigned short amountMinEl = СounterMinPrimes();
		amountPrimesInSource -= amountMinEl;
		unsigned short* tempArr = new unsigned short[amountPrimesInSource];;

		for (unsigned short i = 0; i < amountPrimesInSource; i++)
		{
			tempArr[i] = primesInSource[i + amountMinEl];
		}

		delete[] primesInSource;
		primesInSource = tempArr;
	}

	else
	{
		printf("Массив пуст!");
	}

	return*this;
	
}

SequencePrimeNumbers::~SequencePrimeNumbers()
{
	delete[] source;
	delete[] primesInSource;
}
