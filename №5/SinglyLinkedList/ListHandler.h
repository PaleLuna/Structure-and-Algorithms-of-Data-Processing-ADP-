#include "List.h"
#include <ctime>
#include <iostream>
#pragma once

using namespace std;

class ListHandler
{
	public:
		ListHandler();
		void SetLst(const List<int>& newLst);
		void FillingList();
		void DeleteInLst(unsigned index);
		void CopyInLst2();
		bool IsSorted();

	private:
		List<int> lst;
		List<int> lst1;

		void SortingLst();
		void SortingLst1();




};

