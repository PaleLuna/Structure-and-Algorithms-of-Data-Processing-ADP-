#include <iostream>
#include "SieveOfEratosthenes.h"
#include "DynamicSequence.h"
#pragma once

class DynamicPrimeSequence
{
	public:
		void SetUp(DynamicSequence& obj);
		bool TryShow();

		DynamicPrimeSequence& operator--();
		~DynamicPrimeSequence();

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short amountPrimes = 0;
		unsigned short* primeSequence;

		void FindingPrimeNumbers(DynamicSequence& source);

		bool IsPrime(int num);

		void Sort(unsigned short start, unsigned short end);
		void MovingToBeginning(unsigned short start, unsigned short end);

		unsigned short FindMinEl();
		void ResizePrimeSequence();
};
