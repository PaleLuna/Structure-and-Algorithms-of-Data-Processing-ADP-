#pragma once

class ArrayCompressor
{
	public:
		unsigned short* CleaningArr(unsigned short* &source, unsigned currentLen, unsigned short targetLen, unsigned short trash);
		unsigned short* Compressor(unsigned short* &source, unsigned short targetLen);
};
