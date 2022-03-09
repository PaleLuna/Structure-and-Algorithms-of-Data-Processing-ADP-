#include "StaticSequence.h"

void StaticSequence::SetUp(unsigned short userLen, unsigned short userMaxNum)
{
	realMaxNum = ++userMaxNum;
	sourceLen = userLen;

	AutoFillingSource();
}

bool StaticSequence::TryShow()
{
	if (sourceLen == 0) { return false; }

	printf("[\n");
	for (int i = 0; i < sourceLen - 1; i++) { printf("%4i,", source[i]); }
	printf("%4i\n]\n\n", source[sourceLen - 1]);

	return true;
}
unsigned short StaticSequence::GetMaxNum()
{
	return realMaxNum;
}
unsigned short StaticSequence::GetLen()
{
	return sourceLen;
}

void StaticSequence::Add(unsigned short num)
{
	source[sourceLen++] = num;
	realMaxNum = ((realMaxNum < source[sourceLen - 1]) ? source[sourceLen - 1] : realMaxNum);
}
void StaticSequence::AutoFillingSource()
{
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (int i = 0; i < sourceLen; i++)
		source[i] = rand() % realMaxNum + 1;
}

unsigned short StaticSequence::operator[](int num)
{
	return source[num];
}
