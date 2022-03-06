#include <iostream>
#include "SieveOfEratosthenes.h"
#include "Constants.h"
#include "UserInput.h"
#pragma once

class StaticSequence
{
	public:
		void SetUp();
		void AutoSetUp();
		bool TryShowSource();
		bool TryShowPrimes();

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short amountPrimes = 0;

		bool sequenceExist = false;

		unsigned short source[MAX_SIZE];
		unsigned short primeSequence[MAX_SIZE];

		void FillingSource();
		void AutoFillingSource();

		void FillingPrimeSeq();
		void Sort(unsigned short end);

		bool IsPrime(unsigned short num);


};
