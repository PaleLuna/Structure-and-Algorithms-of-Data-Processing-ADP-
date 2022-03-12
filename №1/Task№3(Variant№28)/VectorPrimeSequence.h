#pragma once
#include <iostream>
#include <vector>
#include "SieveOfEratosthenes.h"
#include "VectorSequence.h"

class VectorPrimeSequence
{
	public:
		void SetUp(VectorSequence& obj);
		bool TryShow();

	private:
		SieveOfEratosthenes sieveOfEratosthenes;

		vector<unsigned short> primeSequence;

		bool TryFillingPrimes(VectorSequence& source);
		void Sort(unsigned short start, unsigned short end);
		void MovingToBeginning(unsigned short start, unsigned short end);
		bool IsPrime(int num);
};

