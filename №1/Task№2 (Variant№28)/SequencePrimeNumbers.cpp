#include "SequencePrimeNumbers.h"

void SequencePrimeNumbers::SetUp(unsigned short userLen, unsigned short userNum)
{
	if ((amountPrimesInSource != 0) && (sourceLen != 0))
	{
		amountPrimesInSource = 0;
		sourceLen = 0;

		delete[] source;
		delete[] primesInSource;
	}

	if(maxNum != userNum) { sieveOfEratosthenes.SetAll(userNum); }
	
	maxNum = userNum;
	sourceLen = userLen;

	source = new unsigned short[sourceLen];
	primesInSource = new unsigned short[sourceLen];

	SourceFilling();
	FindingPrimeNumbers();
}

bool SequencePrimeNumbers::TryShowSource()
{
	if (sourceLen == 0) { return false; }
	printf("[\n");
	for (int i = 0; i < sourceLen - 1; i++) { printf("%5i,", source[i]); }
	printf("%5i\n]\n\n", source[sourceLen - 1]);
}
bool SequencePrimeNumbers::TryShowPrimes()
{
	if (amountPrimesInSource == 0) { return false; }
	printf("[\n");
	for (int i = 0; i < amountPrimesInSource - 1; i++) { printf("%5i,", primesInSource[i]); }
	printf("%5i\n]\n\n", primesInSource[amountPrimesInSource - 1]);

	return true;
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
	//Перебор элементов основного массива
	for (int i = 0; i < sourceLen; i++)
	{
		if (IsPrime(source[i]))
		{
			unsigned short indOfLastElInFillable = amountPrimesInSource++; // Индекс последнего простого числа в массиве

			primesInSource[indOfLastElInFillable] = source[i];
			if (indOfLastElInFillable > 0) { PrimeSort(indOfLastElInFillable); }
		}
	}
	//Уменьшение размера массива
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
void SequencePrimeNumbers::PrimeSort(int end)
{
	for (int i = 0; i < end; i++)
	{
			if (primesInSource[end] < primesInSource[i]) { std::swap(primesInSource[i], primesInSource[end]); }
	}
}

unsigned short SequencePrimeNumbers::СounterMinPrimes()
{
	unsigned short minEl = primesInSource[0];//минимальный элемент
	unsigned short counter = 1;//счетчик минимальных элементов в массиве

	for (int i = 1; i < amountPrimesInSource; i++)
	{
		if (primesInSource[i] == minEl) { counter++; continue; }
		break;
	}
	return counter;
}

SequencePrimeNumbers& SequencePrimeNumbers::operator--()
{
	//только если количество элементов больше нуля
	if (amountPrimesInSource > 0)
	{
		unsigned short amountMinEl = СounterMinPrimes(); //количество минимальных чисел
		amountPrimesInSource -= amountMinEl; //Новый размер массива простых чисел

		unsigned short* tempArr = new unsigned short[amountPrimesInSource]; //Временный массив

		for (unsigned short i = 0; i < amountPrimesInSource; i++)
		{
			tempArr[i] = primesInSource[i + amountMinEl];
		}
		
		delete[] primesInSource; //удаление массива до сжатия
		primesInSource = tempArr;
	}
	else { printf("Массив пуст!\n"); }

	return*this;
}

SequencePrimeNumbers::~SequencePrimeNumbers()
{
	delete[] source;
	delete[] primesInSource;
}
