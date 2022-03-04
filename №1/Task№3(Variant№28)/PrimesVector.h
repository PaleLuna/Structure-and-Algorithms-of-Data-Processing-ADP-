#include <iostream>
#include <vector>
#include "SieveOfEratosthenes.h"
#pragma once

using namespace std;

class PrimesVector
{
	public:
		void SetVal(unsigned short userLen, unsigned short userMaxNum);

		bool TryShowSource();
		bool TryShowPrimes();

		bool TryFillingPrimes();

		unsigned short GetAmountLargeCompNums();

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short maxNum;
		unsigned short maxLen;
		short amountLargeCompositeNums;

		vector<unsigned short> source;
		vector<unsigned short> primesInSource;

		
		void FillingSource();
		void PrimesSort(int end);
		bool IsPrime(int num);
};

