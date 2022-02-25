#include "SequencePrimeNumbers.h"

SequencePrimeNumbers::SequencePrimeNumbers(unsigned short userLen, unsigned short userNum)
{
	maxLen = userLen;
	maxNum = userNum;

	source = new unsigned short[maxLen];
	primesInSource = new unsigned short[maxLen];

	SourceFilling();
	printf("�������� ������ ����������� �����:\n");
	ShowSource();

	//FindingPrimeNumbers();
}

void SequencePrimeNumbers::ShowSource()
{
	if (maxLen > 0)
	{
		printf("[\n");
		//����� ������� � ������� � ��������� ���������������
		for (unsigned short i = 0; i < maxLen - 1; i++)
		{
			printf("%5i,", source[i]);
			if ((i + 1) % 10 == 0)
			{
				printf("\n");
			}
		}

		printf("%5i\n]\n\n", source[maxLen - 1]);
	}
	else
	{
		printf("������ ������\n");
	}
}
void SequencePrimeNumbers::ShowPrimes()
{
	if (amountPrimesInSource > 0)
	{
		printf("[\n");
		//����� ������� � ������� � ��������� ���������������
		for (unsigned short i = 0; i < amountPrimesInSource - 1; i++)
		{
			printf("%5i,", primesInSource[i]);
			if ((i + 1) % 10 == 0)
			{
				printf("\n");
			}
		}

		printf("%5i\n]\n\n", primesInSource[amountPrimesInSource - 1]);
	}
	else
	{
		printf("������ ������\n");
	}
}

void SequencePrimeNumbers::SourceFilling()
{
	//������������� ���������� ��������� �����
	srand(time(NULL));
	//���������� ������� ���������� �������
	for (int i = 0; i < maxLen; i++)
		source[i] = rand() % maxNum + 1;
}
void SequencePrimeNumbers::FindingPrimeNumbers()
{

	int actualLengthPrime; //�������������� ����� ������������������ ������� �����
	unsigned short* arrayOfPrimes = SieveOfEratosthenes(maxNum, actualLengthPrime);//������, �������� ������������������ ������� �����
	//CleaningArr(arrayOfPrimes, maxNum, actualLengthPrime, 0);


	//����� ���������� � ������� ��������� ������
	for (int i = 0; i < maxLen; i++)
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
				unsigned short indOfLastElInFillable = amountPrimesInSource; //������ ���������� �������� � ����������� �������
				//������� �������� �����, �� ������� ������������ ������������������
				primesInSource[indOfLastElInFillable] = source[i];
				if (indOfLastElInFillable > 0)
				{
					for (int j = 1; j <= indOfLastElInFillable; j++)
					{
						for (int k = 0; k < indOfLastElInFillable; k++)
						{
							if (primesInSource[k] > primesInSource[j]) { std::swap(primesInSource[j], primesInSource[k]); }
						}
					}
				}

				amountPrimesInSource++;
				break;
			}

			if (left > right) { break; }
		}
	}
	CleaningArr(primesInSource, amountPrimesInSource);
	delete[] arrayOfPrimes;
}

SequencePrimeNumbers::~SequencePrimeNumbers()
{
	delete[] source;
	delete[] primesInSource;
}