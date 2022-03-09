#include "DynamicSequence.h"

void DynamicSequence::SetUp(unsigned short userLen, unsigned short userNum)
{
	if (size != 0)
	{
		delete[] sequence;
	}
	size = userLen;
	maxNum = userNum;

	ResizeSequence();
	Filling();
}

unsigned short DynamicSequence::GetSize()
{
	return size;
}
unsigned short DynamicSequence::GetMaxNum()
{
	return maxNum;
}

bool DynamicSequence::TryShow()
{
	if (size == 0) { return false; }
	printf("[\n");
	for (int i = 0; i < size - 1; i++) { printf("%5i,", sequence[i]); }
	printf("%5i\n]\n\n", sequence[size - 1]);

	return true;
}

void DynamicSequence::Add(int num)
{
	size = 0;
	sequence[size++] = num;
	maxNum = ((maxNum < sequence[size - 1]) ? sequence[size - 1] : maxNum);
}
void DynamicSequence::Filling()
{
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (int i = 0; i < size; i++)
		sequence[i] = rand() % maxNum + 1;
}

void DynamicSequence::ResizeSequence()
{
	unsigned short* temp = new unsigned short[size];

	for (unsigned short i = 0; i < size; i++) { temp[i] = sequence[i]; }

	delete[] sequence;
	sequence = temp;
}

unsigned short DynamicSequence::operator[](int num)
{
	return sequence[num];
}

DynamicSequence::~DynamicSequence()
{
	delete[] sequence;
}
