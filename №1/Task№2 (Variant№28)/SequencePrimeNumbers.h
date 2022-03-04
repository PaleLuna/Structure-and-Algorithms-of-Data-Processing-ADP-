#include <iostream>
#include "SieveOfEratosthenes.h"
#pragma once

class SequencePrimeNumbers
{
	public:
		SequencePrimeNumbers(unsigned short userLen, unsigned short userNum);
		~SequencePrimeNumbers();

		void ShowPrimes();
		void ShowSource();

		SequencePrimeNumbers& operator--();

	

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short sourceLen;
		unsigned short maxNum;
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
