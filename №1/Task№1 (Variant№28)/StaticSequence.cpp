#include "StaticSequence.h"

void StaticSequence::AutoSetUp()
{
	AutoFillingSource();
	FillingPrimeSeq();

	sequenceExist = true;
}
void StaticSequence::SetUp()
{
	FillingSource();
	FillingPrimeSeq();

	sequenceExist = true;
}

bool StaticSequence::TryShowSource()
{
	if (!sequenceExist) { return false; }
	printf("[\n");
	for (int i = 0; i < MAX_SIZE - 1; i++) { printf("%5i,", source[i]); }
	printf("%5i\n]\n\n", source[MAX_SIZE - 1]);
}
bool StaticSequence::TryShowPrimes()
{
	if (!sequenceExist) { return false; }
	printf("[\n");
	for (int i = 0; i < amountPrimes - 1; i++) { printf("%5i,", primeSequence[i]); }
	printf("%5i\n]\n\n", primeSequence[amountPrimes - 1]);
}

void StaticSequence::AutoFillingSource()
{
	//������������� ���������� ��������� �����
	srand(time(NULL));

	//���������� ������� ���������� �������
	for (int i = 0; i < MAX_SIZE; i++)
		source[i] = rand() % MAX_NUM + 1;
}
void StaticSequence::FillingSource()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("sourece[%i] = ", i + 1);
		unsigned short userNum = UserInput(0, MAX_NUM);

		source[i] = userNum;
	}
}

void StaticSequence::FillingPrimeSeq()
{
	//������� ��������� ��������� �������
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (IsPrime(source[i]))
		{
			unsigned short indOfLastElInFillable = amountPrimes++; // ������ ���������� �������� ����� � �������

			primeSequence[indOfLastElInFillable] = source[i];
			if (indOfLastElInFillable > 0) { Sort(indOfLastElInFillable); }
		}
	}
}

bool StaticSequence::IsPrime(unsigned short num)
{
	int actualLengthPrime = sieveOfEratosthenes.GetAmountPrimes(); //�������������� ����� ������������������ ������� �����
	unsigned short* arrayOfPrimes = sieveOfEratosthenes.GetSequence(); //������, �������� ������������������ ������� 

	int right = actualLengthPrime - 1; //������ �������
	int left = 0; //����� �������

	while (true)
	{
		int mid = (right + left) / 2;

		if (num > arrayOfPrimes[mid]) { left = mid + 1; }
		else if (num < arrayOfPrimes[mid]) { right = mid - 1; }
		else { return true; }

		if (left > right) { return false; }
	}
}
void StaticSequence::Sort(unsigned short end)
{
	for (int i = 0; i < end; i++)
	{
		if (primeSequence[end] < primeSequence[i]) { std::swap(primeSequence[i], primeSequence[end]); }
	}
}

