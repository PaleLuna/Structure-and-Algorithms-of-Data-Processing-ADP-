#include "FindingPrimeNumbers.h"

unsigned short* SieveOfEratosthenes(unsigned short maxNum, int& realLen);

unsigned short* FindingPrimeNumbers(unsigned short* source, unsigned short maxNum, unsigned short maxLen, int& amountPrimes)
{
	printf("%i, %i\n", maxLen, maxNum);

	int actualLengthPrime; //�������������� ����� ������������������ ������� �����
	unsigned short* arrayOfPrimes = SieveOfEratosthenes(maxNum, actualLengthPrime);//������, �������� ������������������ ������� 

	printf("%i\n", actualLengthPrime);

	unsigned short* fillable = new unsigned short[maxLen]; //������, � ������� ����� �������� ������� �����
	unsigned short indOfLastElInFillable = 0; //������ ���������� �������� � ����������� �������


	//����� ���������� � ������� ��������� ������
	for (int i = 0; i < maxLen; i++)
	{
		int right = actualLengthPrime - 1;
		int left = 0;

		while (true)
		{
			int mid = (right + left) / 2;
			printf("%i ? %i\n", source[i], arrayOfPrimes[mid]);
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
	printf("%i\n", indOfLastElInFillable);
	amountPrimes = indOfLastElInFillable;
	return fillable;
}

//�������� "������ ����������"
unsigned short* SieveOfEratosthenes(unsigned short maxNum, int& realLen)
{
	unsigned short* tempArr = new unsigned short[maxNum + 1]; //��������� ������ ������������������ ����� �� 0 �� MAX_NUM ������������
	unsigned short counterOfPrimes = 0;

	//���������� �������
	for (int i = 0; i <= maxNum; i++)
	{
		tempArr[i] = i;
	}

	//������� �� �������� ������� ������, ����� �����������
	tempArr[1] = 0;
	counterOfPrimes++;

	int s = (int)pow(maxNum, 0.5f);

	//���������� �������, ����� ������ ���� ��������� ����� ������
	for (int i = 2; i < maxNum; i++)
	{
		if (tempArr[i] != 0)
		{
			for (int j = 2 * i; j <= maxNum; j += i)
			{
				if (tempArr[j] != 0)
				{
					tempArr[j] = 0;
					counterOfPrimes++;
				}
			}
		}
	}

	realLen = maxNum - counterOfPrimes;

	CleaningArr(tempArr, maxNum, realLen, 0);

	return tempArr;
}