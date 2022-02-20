#include "FindingPrimeNumbers.h"

void SieveOfEratosthenes(unsigned short* fillable, unsigned short& amountPrimes);

void FindingPrimeNumbers(int* source, int* fillable, int &amountPrimes)
{
	unsigned short arrayOfPrimes[MAX_NUM];//������, �������� ������������������ ������� �����
	unsigned short actualLengthPrime; //�������������� ����� ������������������ ������� �����
	unsigned short indOfLastElInFillable = 0; //������ ���������� �������� � ����������� �������

	//��������� ������������������ ������� �����
	SieveOfEratosthenes(arrayOfPrimes, actualLengthPrime);

	//����� ���������� � ������� ��������� ������
	for (int i = 0; i < MAX_LEN; i++)
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
				//������� �������� �����, �� ������� ������������ ������������������
				fillable[indOfLastElInFillable] = source[i];
				if (indOfLastElInFillable > 0)
				{
					for (int j = 1; j <= indOfLastElInFillable; j++)
					{
						for (int k = 0; k < indOfLastElInFillable; k++)
						{
							if (fillable[k] > fillable[j]) { std::swap(fillable[j], fillable[k]); }
						}
					}
				}

				indOfLastElInFillable++;
				break;
			}

			if (left > right) { break; }
		}
	}

	amountPrimes = indOfLastElInFillable;
}

//�������� "������ ����������"
void SieveOfEratosthenes(unsigned short* fillable, unsigned short& realLen)
{
	unsigned short tempArr[MAX_NUM + 1]; //��������� ������ ������������������ ����� �� 0 �� MAX_NUM ������������
	unsigned short counterOfPrimes = 0;

	//���������� �������
	for (int i = 0; i <= MAX_NUM; i++)
	{
		tempArr[i] = i;
	}

	//������� �� �������� ������� ������, ����� �����������
	tempArr[1] = 0;
	counterOfPrimes++;

	//���������� �������, ����� ������ ���� ��������� ����� ������
	for (int i = 2; i < pow(MAX_NUM, 0.5F); i++)
	{
		if (tempArr[i] != 0)
		{
			for (int j = 2 * i; j <= MAX_NUM; j += i)
			{
				if (tempArr[j] != 0)
				{
					tempArr[j] = 0;
					counterOfPrimes++;
				}
			}
		}
	}

	realLen = MAX_NUM - counterOfPrimes;

	ArrayCleaning(tempArr, fillable, 0);
}