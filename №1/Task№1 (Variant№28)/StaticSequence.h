#include <iostream>
#include "Constants.h"
#pragma once

class StaticSequence
{
	public:
		void SetUp(unsigned short userLen, unsigned short userMaxNum);
		bool TryShow();

		unsigned short GetMaxNum();
		unsigned short GetLen();
		void Add(unsigned short num);

		unsigned short operator[](int num);

	private:
		unsigned short sourceLen = 0;
		unsigned short realMaxNum = 0;

		unsigned short source[MAX_SIZE];

		void AutoFillingSource();

};
