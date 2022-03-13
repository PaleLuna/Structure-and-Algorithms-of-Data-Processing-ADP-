#include <vector>
#pragma once

using namespace std;

class SieveOfEratosthenes
{
	public:
		vector<unsigned short> primesNumber;
		void SetAll(unsigned short limit);

	private:
		void CreateSequence();
};

