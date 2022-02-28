#include <iostream>
#include <vector>
#pragma once

using namespace std;

class PrimesVector
{
	public:
		PrimesVector(unsigned short userLen, unsigned short userMaxNum);

		void ShowSource();
		void ShowPrimes();
		
		PrimesVector& operator--();

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		unsigned short maxNum;

		vector<unsigned short> source;
		vector<unsigned short> primesInSource;

		void FillingPrimes();
		void FillingSource();
};

