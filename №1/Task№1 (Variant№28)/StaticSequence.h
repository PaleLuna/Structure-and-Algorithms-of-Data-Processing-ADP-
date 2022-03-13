#include <iostream>
#include "Constants.h"
#pragma once

class StaticSequence
{
	public:
		void SetUp(unsigned short userLen, unsigned short userMaxNum);
		void Add(unsigned short num);
		void Reset();
		
		bool TryShow();
		unsigned short GetMaxNum();
		unsigned short GetLen();

		unsigned short operator[](int index);

	private:
		unsigned short sourceLen = 0;
		unsigned short realMaxNum = 0;

		unsigned short source[MAX_SIZE];

		void AutoFillingSource();

};
