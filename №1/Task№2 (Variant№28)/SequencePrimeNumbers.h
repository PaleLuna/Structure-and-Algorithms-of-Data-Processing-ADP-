#include <iostream>
#include <cmath>
#include <ctime>
#pragma once

class SequencePrimeNumbers
{
	public:
		SequencePrimeNumbers(unsigned short userLen, unsigned short userNum);
		~SequencePrimeNumbers();

		void ShowPrimes();

	private:
		unsigned short maxLen;
		unsigned short maxNum;

		unsigned short amountPrimesInSource = 0;
		unsigned short* source;
		unsigned short* primesInSource;
		
		void SourceFilling();
		void FindingPrimeNumbers();
		void ShowSource();

		
	
};



