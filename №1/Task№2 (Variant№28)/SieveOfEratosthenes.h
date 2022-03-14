#include <cmath>
#include <iostream>
#pragma once

class SieveOfEratosthenes
{
	public:
		unsigned short GetAmountPrimes();
		unsigned short* GetSequence();
		void SetAll(unsigned short limit);

		~SieveOfEratosthenes();

	private:
		unsigned short sequenceLimit;
		unsigned short amountPrimes = 0;
		unsigned short* primesNumber;

		void CreateSequence();
		void ZeroSorting();
};
