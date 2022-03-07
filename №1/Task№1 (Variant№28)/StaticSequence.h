#include <iostream>
#include "SieveOfEratosthenes.h"
#include "Constants.h"
#include "UserInput.h"
#pragma once

class StaticSequence
{
	public:
		void SetUp();
		void SetUp(unsigned short userLen, unsigned short userMaxNum);
		bool TryShowSource();
		bool TryShowPrimes();

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short amountPrimes = 0;
		unsigned short sourceLen = 0;
		unsigned short realMaxNum = 0;

		unsigned short source[MAX_SIZE];
		unsigned short primeSequence[MAX_SIZE];

		void FillingSource();
		void AutoFillingSource();

		void FillingPrimeSeq();
		void Sort(unsigned short end);

		bool IsPrime(unsigned short num);
};
