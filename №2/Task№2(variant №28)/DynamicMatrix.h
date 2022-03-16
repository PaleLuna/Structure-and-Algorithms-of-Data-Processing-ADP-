#include <iostream>
#pragma once
class DynamicMatrix
{
	public:
		void SetUp(unsigned userOrder, unsigned maxNum);
		void SetUp(unsigned userOrder);

		void Add(unsigned row, unsigned col, unsigned num);
		bool TryShow();
		bool TryTranspose();

		~DynamicMatrix();

	private:
		unsigned maxNum = 0;

		unsigned orderMatrix = 0;
		unsigned** dynamicMatrix;

		void Filling();
		void Transpose();

		void ClearMatrix();
};