#include "PrimesVector.h"
#include "SieveOfEratosthenes.h"

PrimesVector::PrimesVector(unsigned short userLen, unsigned short userMaxNum)
{
	maxNum = userMaxNum;

	source.resize(userLen);
	primesInSource.resize(userLen);
}

void PrimesVector::ShowSource()
{
	printf("[\n");
	for (int i = 0; i < source.size() - 1; i++)
	{
		printf("%5i,", source.at(i));
	}
	printf("%5i\n]\n\n", source.at(source.size() - 1));
}
void PrimesVector::ShowPrimes()
{
	printf("[\n");
	for (int i = 0; i < primesInSource.size() - 1; i++)
	{
		printf("%5i,", primesInSource.at(i));
	}
	printf("%5i\n]\n\n", primesInSource.at(primesInSource.size() - 1));
}

void PrimesVector::FillingSource()
{
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (unsigned short &el:source)
		el = rand() % maxNum + 1;
}
void PrimesVector::FillingPrimes()
{
	vector<unsigned short> arrayOfPrimes = sieveOfEratosthenes.primesNumber;//ћассив, хран€щий последовательность простых 

	unsigned short indOfLastElInFillable = 0;

	//ѕоиск совпадений с помощью бинарного поиска
	for (int i = 0; i < source.size(); i++)
	{
		int right = arrayOfPrimes.size() - 1;
		int left = 0;

		while (true)
		{
			int mid = (right + left) / 2;
			if (source[i] > arrayOfPrimes.at(mid)) { left = mid + 1; }
			else if (source.at(i) < arrayOfPrimes.at(mid)) { right = mid - 1; }
			else
			{
				//¬ставка простого числа, не наруша€ возрастающую последовательность
				primesInSource.at(indOfLastElInFillable) = source.at(i);
				if (indOfLastElInFillable > 0)
				{
					for (int j = 1; j <= indOfLastElInFillable; j++)
					{
						for (int k = 0; k < indOfLastElInFillable; k++)
						{
							if (primesInSource.at(k) > primesInSource.at(j)) { std::swap(primesInSource.at(j), primesInSource.at(k)); }
						}
					}
				}

				break;
			}

			if (left > right) { break; }
		}
	}

	primesInSource.resize(indOfLastElInFillable);
}


