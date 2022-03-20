#include <iostream>
#include "Constants.h"
#pragma once

class StaticMatrix
{
	public:
		void SetUp(unsigned userOrder, unsigned userMaxNum);
		void SetUp(unsigned userOrder);
		bool TryShow();

		void Add(unsigned row, unsigned col, unsigned num);

	private:
		unsigned realOrder = 0;
		unsigned maxNum = 0;
		unsigned matrix[MAX_ORDER][MAX_ORDER];

		void GeneratingElements();
};

