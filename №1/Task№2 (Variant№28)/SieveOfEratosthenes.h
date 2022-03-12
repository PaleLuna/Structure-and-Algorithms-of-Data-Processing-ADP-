#include <cmath>
#include <iostream>
#pragma once

class SieveOfEratosthenes
{
	public:
		unsigned short* primesNumber;
		unsigned short amountPrimes = 0;

		~SieveOfEratosthenes();
		void SetAll(unsigned short limit);

	private:
		unsigned short sequenceLimit;

		void FillingSequence();
		void ZeroSorting();
};
