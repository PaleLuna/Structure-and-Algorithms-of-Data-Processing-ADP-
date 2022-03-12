#include <iostream>
#include "Constants.h"
#pragma once

class DynamicSequence
{
	public:
		void SetUp(unsigned short userLen, unsigned short userNum);

		unsigned short GetSize();
		unsigned short GetMaxNum();

		bool TryShow();
		void Add(int num);
		void Reset();

		unsigned short operator[](int num);
		~DynamicSequence();

	private:
		unsigned short size = 0;
		unsigned short maxNum = 0;
	
		unsigned short* sequence;

		void Filling();
};
