#include <cmath>
#include <iostream>
#include "Constants.h"
#pragma once

class SieveOfEratosthenes
{
	public:
		SieveOfEratosthenes();
		unsigned short GetAmountPrimes();
		unsigned short* GetSequence();


	private:
		unsigned short amountPrimes = 0;
		unsigned short primeSequence[MAX_NUM];

		void CreateSequense();
		void ZeroSorting();

};

