#include "VectorPrimeSequence.h"

bool VectorPrimeSequence::TryShow()
{
	if (primeSequence.empty()) { return false; }

	printf("[\n");
	for (int i = 0; i < primeSequence.size() - 1; i++) { printf("%5i,", primeSequence.at(i)); }
	printf("%5i\n]\n\n", primeSequence.at(primeSequence.size() - 1));

	return true;
}

void VectorPrimeSequence::SetUp(VectorSequence& obj)
{
	if (!primeSequence.empty()) { primeSequence.clear(); }
	sieveOfEratosthenes.SetAll(obj.GetMaxNum());
	TryFillingPrimes(obj);
}

bool VectorPrimeSequence::TryFillingPrimes(VectorSequence& source)
{
	if (!primeSequence.empty()) { return false; }
	unsigned short indOfLastElInFillable = 0;
	unsigned short repeat = 1;

	//Перебор элементов основного массива
	for (int i = 0; i < source.GetSize(); i++)
	{
		if (IsPrime(source[i]))
		{
			//Вставка простого числа, не нарушая возрастающую последовательность
			primeSequence.push_back(source[i]);

			if (indOfLastElInFillable > 1)
			{
				if (primeSequence.at(indOfLastElInFillable) == primeSequence.at(0))
				{
					MovingToBeginning(repeat++, indOfLastElInFillable);
					continue;
				}
				Sort(repeat, indOfLastElInFillable);
			}
			indOfLastElInFillable++;
		}
	}
	return true;
}

bool VectorPrimeSequence::IsPrime(int num)
{
	vector<unsigned short> arrayOfPrimes = sieveOfEratosthenes.primesNumber; //Массив, хранящий последовательность простых чисел

	int right = arrayOfPrimes.size() - 1;
	int left = 0;

	while (true)
	{
		int mid = (right + left) / 2;
		if (num > arrayOfPrimes.at(mid)) { left = mid + 1; }
		else if (num < arrayOfPrimes.at(mid)) { right = mid - 1; }
		else
		{
			return true;
		}

		if (left > right) { return false; }
	}
}
void VectorPrimeSequence::Sort(unsigned short start, unsigned short end)
{
	for (int i = start; i < end; i++)
		if (primeSequence.at(end) < primeSequence.at(i)) { std::swap(primeSequence.at(i), primeSequence.at(end)); }
}
void VectorPrimeSequence::MovingToBeginning(unsigned short start, unsigned short end)
{
	for (int j = end; j >= start;)
		std::swap(primeSequence.at(end--), primeSequence.at(--j));
}