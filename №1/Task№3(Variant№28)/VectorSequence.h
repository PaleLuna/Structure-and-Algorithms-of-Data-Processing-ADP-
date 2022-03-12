#include <iostream>
#include <vector>
#pragma once

using namespace std;

class VectorSequence
{
	public:
		unsigned short GetSize();
		unsigned short GetMaxNum();
		bool IsEmpty();

		void SetUp(unsigned short userLen, unsigned short userMaxNum);
		void Add(int num);
		void Reset();

		bool TryShow();
		unsigned short GetAmountLargeCompNums();

		unsigned short operator[](int ind);

	private:

		unsigned short maxNum = 0;
		short amountLargeCompositeNums;

		vector<unsigned short> sequence;
		
		void FillingSource();
};

