#include <iostream>
#include "SieveOfEratosthenes.h"
#pragma once

class SequencePrimeNumbers
{
	public:
		void SetUp(unsigned short userLen, unsigned short userNum);
		~SequencePrimeNumbers();

		bool TryShowPrimes();
		bool TryShowSource();

		SequencePrimeNumbers& operator--();

	

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short sourceLen = 0;
		unsigned short maxNum = 0;
		unsigned short amountPrimesInSource = 0;
	
		unsigned short* source;
		unsigned short* primesInSource;

		void SourceFilling();
		void FindingPrimeNumbers();
		void ResizePrimeSequence();
		void PrimeSort(int end);


		bool IsPrime(int num);
		unsigned short ÑounterMinPrimes();
};
