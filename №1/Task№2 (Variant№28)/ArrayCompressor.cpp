#include "ArrayCompressor.h"

unsigned short* ArrayCompressor::CleaningArr(unsigned short* &source, unsigned currentLen, unsigned short targetLen, unsigned short trash)
{
	unsigned short* fillable = new unsigned short[targetLen];
	unsigned short currentIndex = 0;

	for (unsigned short i = 0; i < currentLen; i++)
	{
		if ((source[i] != trash) && (currentIndex < targetLen))
		{
			fillable[currentIndex] = source[i];
			currentIndex++;
		}
	}
	delete[] source;
	return fillable;
}
unsigned short* ArrayCompressor::Compressor(unsigned short* &source, unsigned short targetLen)
{
	unsigned short* fillable = new unsigned short[targetLen];

	for (unsigned short i = 0; i < targetLen; i++)
	{
		
		fillable[i] = source[i];
	}

	delete[] source;
	return fillable;
}