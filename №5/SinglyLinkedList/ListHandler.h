#include "List.h"
#include <ctime>
#include <iostream>
#pragma once


class ListHandler
{
	public:
		void CreateList(unsigned size);

		void PrintLists();

		void CopyLst();
		bool IsSorted();

	private:
		List<int> originList;
		List<int> copyList;

		void SortingOrigin();
		void SortingCopy();
		void DeleteInOriginal(int index);

		int GetHighDigit(int var);
		int GetLowDigit(int var);
};