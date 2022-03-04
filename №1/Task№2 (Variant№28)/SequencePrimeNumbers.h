#include <iostream>
#include "SieveOfEratosthenes.h"
#include "ArrayCompressor.h"

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
		ArrayCompressor arrayCompressor;

		unsigned short sourceLen;
		unsigned short maxNum;
		unsigned short amountPrimesInSource = 0;
	
		unsigned short* source;
		unsigned short* primesInSource;

		void SourceFilling();
		void FindingPrimeNumbers();

		bool IsPrime(int num);
		void PrimeSort(int end);
};
