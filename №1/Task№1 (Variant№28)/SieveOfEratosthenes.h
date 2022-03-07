#include <cmath>
#include <iostream>
#include "Constants.h"
#pragma once

class SieveOfEratosthenes
{
	public:
		void SetUp(unsigned short seqLim);
		unsigned short GetAmountPrimes();
		unsigned short* GetSequence();


	private:
		unsigned short amountPrimes = 0;
		unsigned short sequenceLimit;
		unsigned short primeSequence[MAX_NUM+1];

		void CreateSequense();
		void ZeroSorting();

};

