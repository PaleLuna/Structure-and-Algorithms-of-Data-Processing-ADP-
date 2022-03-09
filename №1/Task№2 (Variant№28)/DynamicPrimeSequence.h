#include <iostream>
#include "SieveOfEratosthenes.h"
#include "DynamicSequence.h"
#pragma once

class DynamicPrimeSequence
{
	public:
		void SetUp(DynamicSequence& obj);
		bool TryShow();
		void FindingPrimeNumbers();

		DynamicPrimeSequence& operator--();
		~DynamicPrimeSequence();

	private:
		SieveOfEratosthenes sieveOfEratosthenes;
		DynamicSequence source;

		unsigned short counterFirstIncommingNum = 1;
		unsigned short amountPrimes = 0;
		unsigned short* primeSequence;

		bool IsPrime(int num);

		void Sort(unsigned short start, unsigned short end);
		void MovingToBeginning(unsigned short start, unsigned short end);

		unsigned short ÑounterMinPrimes();
		void ResizePrimeSequence();

};
