#include "VectorSequence.h"
#include "SieveOfEratosthenes.h"

unsigned short VectorSequence::GetSize()
{
	return sequence.size();
}
unsigned short VectorSequence::GetMaxNum()
{
	return maxNum;
}
bool VectorSequence::IsEmpty()
{
	return sequence.empty();
}

void VectorSequence::SetUp(unsigned short userLen, unsigned short userMaxNum)
{
	maxNum = userMaxNum;
	if (!sequence.empty())
	{
		Reset();
	}
	
	sequence.resize(userLen);
	FillingSource();
}
void VectorSequence::Reset()
{
	sequence.clear();
	amountLargeCompositeNums = -1;
}
bool VectorSequence::TryShow()
{
	if (sequence.empty()) { return false; }

	printf("[\n");
	for (int i = 0; i < sequence.size() - 1; i++) { printf("%5i,", sequence.at(i)); }
	printf("%5i\n]\n\n", sequence.at(sequence.size() - 1));

	return true;
}

void VectorSequence::Add(int num)
{
	sequence.push_back(num);
	maxNum = ((maxNum < num) ? num : maxNum);
}
void VectorSequence::FillingSource()
{
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (unsigned short& el : sequence) { el = rand() % maxNum + 1; }	
}

unsigned short VectorSequence::GetAmountLargeCompNums()
{
	if (sequence.empty()) { return 0; }
	if (amountLargeCompositeNums > -1) { return amountLargeCompositeNums; }
	amountLargeCompositeNums++;

	for (int i = 0; i < sequence.size(); i++)
	{
		unsigned counter = 2;
		float sqrtNum = sqrt(sequence.at(i));
		if ((sqrtNum - floor(sqrtNum)) == 0)
		{ 
			counter++; 
			sqrtNum--;
		}

		sqrtNum = (int)sqrtNum;
		for (int j = 2; j <= sqrtNum; j++)
		{
			if (sequence.at(i) % j == 0) { counter += 2; }
		}

		if (counter > 3) { amountLargeCompositeNums++; }
	}

	return amountLargeCompositeNums;
}
unsigned short VectorSequence::operator[](int ind)
{
	return sequence.at(ind);
}
