#include <iostream>
#include "Constants.h"
#include "StaticSequence.h"
#include "SieveOfEratosthenes.h"
#pragma once

class StaticPrimeSequence
{
	public:
		bool TryShow();
		void FillingPrimeSeq(StaticSequence& source);

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short amountPrimes;

		unsigned short primeSequence[MAX_SIZE];

		void Sort(unsigned short start, unsigned short end);
		void MovingToBeginning(unsigned short start, unsigned short end);

		bool IsPrime(unsigned short num);
};

