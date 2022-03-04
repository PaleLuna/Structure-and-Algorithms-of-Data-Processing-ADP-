#include "PrimesVector.h"
#include "SieveOfEratosthenes.h"

void PrimesVector::SetVal(unsigned short userLen, unsigned short userMaxNum)
{
	maxNum = userMaxNum;
	maxLen = userLen;
	amountLargeCompositeNums = -1;

	if (!source.empty())
	{
		source.clear();
		primesInSource.clear();
	}
	

	sieveOfEratosthenes.SetAll(maxNum);
	FillingSource();
}

bool PrimesVector::TryShowSource()
{
	if (source.empty()) { return false; }

	printf("[\n");
	for (int i = 0; i < source.size() - 1; i++) { printf("%5i,", source.at(i)); }
	printf("%5i\n]\n\n", source.at(source.size() - 1));

	return true;
}
bool PrimesVector::TryShowPrimes()
{
	if (primesInSource.empty()) { return false; }

	printf("[\n");
	for (int i = 0; i < primesInSource.size() - 1; i++) { printf("%5i,", primesInSource.at(i)); }
	printf("%5i\n]\n\n", primesInSource.at(primesInSource.size() - 1));

	return true;
}

void PrimesVector::FillingSource()
{
	source.resize(maxLen);
	//������������� ���������� ��������� �����
	srand(time(NULL));

	//���������� ������� ���������� �������
	for (unsigned short& el : source) { el = rand() % maxNum + 1; }	
}
bool PrimesVector::TryFillingPrimes()
{
	if (!primesInSource.empty() || source.empty()) { return false; }
	primesInSource.resize(maxLen);

	unsigned short indOfLastElInFillable = 0;

	//������� ��������� ��������� �������
	for (int i = 0; i < source.size(); i++)
	{
		if (IsPrime(source.at(i)))
		{
			//������� �������� �����, �� ������� ������������ ������������������
			primesInSource.at(indOfLastElInFillable) = source.at(i);
			if (indOfLastElInFillable > 0)
			{
				PrimesSort(indOfLastElInFillable);
			}
			indOfLastElInFillable++;
		}
		
	}

	primesInSource.resize(indOfLastElInFillable);
	return true;
}

unsigned short PrimesVector::GetAmountLargeCompNums()
{
	if (source.empty()) { return 0; }
	if (amountLargeCompositeNums > -1) { return amountLargeCompositeNums; }
	amountLargeCompositeNums++;

	for (int i = 0; i < source.size(); i++)
	{
		unsigned counter = 2;
		float sqrtNum = sqrt(source.at(i));

		if ((sqrtNum - floor(sqrtNum)) == 0)
		{ 
			counter++; 
			sqrtNum--;
		}

		sqrtNum = (int)sqrtNum;
		
		for (int j = 2; j <= sqrtNum; j++)
		{
			if (source.at(i) % j == 0) { counter += 2; }
		}

		if (counter > 3) { amountLargeCompositeNums++; }
	}

	return amountLargeCompositeNums;
}

bool PrimesVector::IsPrime(int num)
{
	vector<unsigned short> arrayOfPrimes = sieveOfEratosthenes.primesNumber; //������, �������� ������������������ ������� �����
	
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
void PrimesVector::PrimesSort(int end)
{
	for (int i = 0; i < end; i++)
	{
			if (primesInSource.at(end) < primesInSource.at(i)) { std::swap(primesInSource.at(i), primesInSource.at(end)); }
	}
}