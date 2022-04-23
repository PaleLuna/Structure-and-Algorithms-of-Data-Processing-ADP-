#include "List.h"
#pragma once

class StoreManager
{
	public:
		void UpdateList(const List<Product>& newList);
		void AddProduct(Product& newProduct);
		void PrintProducts();

		void RefreshSort();
		void DeleteAtDate(Time& date);
	private:
		List<Product> storage;

		unsigned borderInd = 1;
		bool byUnreturned = true;

		void SortingByUnreturned();
		void SortingByReturned();
};

