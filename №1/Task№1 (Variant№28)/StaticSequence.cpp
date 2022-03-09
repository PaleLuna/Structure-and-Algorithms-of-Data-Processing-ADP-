#include "StaticSequence.h"

void StaticSequence::SetUp(unsigned short userLen, unsigned short userMaxNum)
{
	sourceLen = userLen;
	amountPrimes = 0;
	if (realMaxNum != userMaxNum)
	{
		realMaxNum = userMaxNum;
		sieveOfEratosthenes.SetUp(realMaxNum);
	}

	AutoFillingSource();
	FillingPrimeSeq();
}
void StaticSequence::SetUp()
{
	unsigned short temp = realMaxNum;
	amountPrimes = 0;
	sourceLen = 0;
	realMaxNum = 0;

	FillingSource();
	if (realMaxNum != temp) { sieveOfEratosthenes.SetUp(realMaxNum); }
	FillingPrimeSeq();
}

bool StaticSequence::TryShowSource()
{
	if (sourceLen == 0) { return false; }
	printf("[\n");
	for (int i = 0; i < sourceLen - 1; i++) { printf("%5i,", source[i]); }
	printf("%5i\n]\n\n", source[sourceLen - 1]);
}
bool StaticSequence::TryShowPrimes()
{
	if (amountPrimes == 0) { return false; }
	printf("[\n");
	for (int i = 0; i < amountPrimes - 1; i++) { printf("%5i,", primeSequence[i]); }
	printf("%5i\n]\n\n", primeSequence[amountPrimes - 1]);
}

void StaticSequence::AutoFillingSource()
{
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (int i = 0; i < sourceLen; i++)
		source[i] = rand() % realMaxNum + 1;
}
void StaticSequence::FillingSource()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("sourece[%i] = ", i + 1);

		unsigned short userNum = UserInput(0, MAX_NUM);
		if (userNum > 0)
		{
			realMaxNum = ((realMaxNum < userNum) ? userNum : realMaxNum);
			source[i] = userNum;
			sourceLen++;
			continue;
		}
		break;
	}
}

void StaticSequence::FillingPrimeSeq()
{
	unsigned short repetitionCounter = -1;

	//ѕеребор элементов основного массива
	for (int i = 0; i < sourceLen; i++)
	{
		if (IsPrime(source[i]))
		{
			unsigned short indOfLastElInFillable = amountPrimes++; // »ндекс последнего простого числа в массиве

			primeSequence[indOfLastElInFillable] = source[i];
			if (primeSequence[indOfLastElInFillable] == primeSequence[0]) { repetitionCounter++; }
			if (indOfLastElInFillable > 1) { Sort(repetitionCounter, indOfLastElInFillable); }
		}
	}
}

bool StaticSequence::IsPrime(unsigned short num)
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
void StaticSequence::Sort(unsigned short start, unsigned short end)
{
	unsigned short el = primeSequence[end];
	if (primeSequence[end] == primeSequence[0])
	{
		for (int j = end - 1; (j > start) && (primeSequence[end] != primeSequence[j]); j--)
		{
			std::swap(primeSequence[end--], primeSequence[j]);
		}
	}
	else
	{
		for (int i = start; i < end; i++)
		{
			if (primeSequence[end] < primeSequence[i]) { std::swap(primeSequence[i], primeSequence[end]); }
		}
	}
}
