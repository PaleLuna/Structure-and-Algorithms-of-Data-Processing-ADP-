#include "ArrayCleaning.h"

void ArrayCleaning(unsigned short* source, unsigned short* fillable, short trash)
{
	int j = 0;
	for (int i = 0; i <= MAX_NUM; i++)
	{
		if (source[i] != trash)
		{
			fillable[j] = source[i];
			j++;
		}
	}
}