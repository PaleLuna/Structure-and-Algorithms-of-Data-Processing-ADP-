#include <cmath>
#include "ArrayCompressor.h"
#pragma once

class SieveOfEratosthenes
{
	public:
		~SieveOfEratosthenes();
		unsigned short* primesNumber;
		unsigned short amountPrimes = 0;
		void SetAll(unsigned short limit);

	private:
		ArrayCompressor arrayCompressor;
		unsigned short sequenceLimit;
		void FillingSequence();
};
