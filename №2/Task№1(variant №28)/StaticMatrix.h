#include <iostream>
#include "Constants.h"
#pragma once

class StaticMatrix
{
	public:
		void SetUp(unsigned userOrder);
		bool TryShow();
		bool TryTranspose();


	private:
		unsigned realOrder;
		unsigned matrix[MAX_ORDER][MAX_ORDER];

		void Filling();
		void Transpose();
};

