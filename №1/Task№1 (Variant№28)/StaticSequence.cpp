#include "StaticSequence.h"

void StaticSequence::SetUp()
{
	max_num = 0;

	FillingSource();
	FillingPrimeSeq();

	sequenceExist = true;
}
void StaticSequence::SetUp(unsigned short maxNum)
{
	max_num = maxNum;

	AutoFillingSource();
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
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (int i = 0; i < MAX_SIZE; i++)
		source[i] = rand() % max_num + 1;
}
void StaticSequence::FillingSource()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("sourece[%i] = ", i + 1);
		unsigned short userNum = UserInput(0);
		max_num = ((max_num < userNum) ? userNum : max_num);

		source[i] = userNum;
	}
}

void StaticSequence::FillingPrimeSeq()
{

}