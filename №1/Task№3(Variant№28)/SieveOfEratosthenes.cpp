#include "SieveOfEratosthenes.h"

void SieveOfEratosthenes::SetAll(unsigned short limit)
{
	primesNumber.resize(limit + 1);
	
	FillingSequence();
}

void SieveOfEratosthenes::FillingSequence()
{
	//������� ����������� ��������� �����
	unsigned short counterStrikeout = 0;

	//���������� �������
	for (int i = 0; i < primesNumber.size(); i++)
	{
		primesNumber.at(i) = i;
	}

	//������� �� �������� ������� ������, ����� �����������
	primesNumber.at(1) = 0;
	counterStrikeout++;

	int sqrtMaxNum = sqrt(primesNumber.size());

	//���������� �������, ����� ������ ���� ��������� ����� ������
	for (int i = 2; i < sqrtMaxNum; i++)
	{
		if (primesNumber.at(i) != 0)
		{
			for (int j = 2 * i; j < primesNumber.size(); j += i)
			{
				if (primesNumber.at(j) != 0)
				{
					primesNumber.at(j) = 0;
					counterStrikeout++;
				}
			}
		}
	}
	primesNumber.resize(primesNumber.size() - ++counterStrikeout);
}