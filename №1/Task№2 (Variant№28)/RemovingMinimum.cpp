#include "RemovingMinimum.h"

void RemovingMinimum(unsigned short*& source, int &len)
{
	if (len > 1)
	{
		unsigned short* fillable = new unsigned short[--len];

		for (int i = 0; i < len; i++)
			fillable[i] = source[i + 1];

		delete[] source;
		source = fillable;
	}

	else
	{
		printf("Длинна массива слишком мала!\n");
	}
	
}