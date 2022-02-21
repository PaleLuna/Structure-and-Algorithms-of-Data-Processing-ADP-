#include "AutomaticFilling.h"

void AutomaticFilling(unsigned short* fillable, unsigned short len, short maxNum)
{
	//»нициадизаци€ генератора случайных чисел
	srand(time(NULL));

	//«аполнение массива случайными числами
	for (int i = 0; i < len; i++)
		fillable[i] = rand() % maxNum + 1;
}