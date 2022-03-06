#include <iostream>
#include "UserInput.h"
#pragma once

class StaticSequence
{
	public:
		void SetUp(unsigned short maxNum);
		void SetUp();
		bool TryShowSource();
		bool TryShowPrimes();

	private:
		static const unsigned short MAX_SIZE = 10;
		unsigned short amountPrimes = 0;
		unsigned short max_num;

		bool sequenceExist = false;

		unsigned short source[MAX_SIZE];
		unsigned short primeSequence[MAX_SIZE];

		void FillingSource();
		void AutoFillingSource();

		void FillingPrimeSeq();
		void FindingPrimes();
		void Sort();

		bool IsPrime(unsigned short num);


};
