#include "StoreManager.h"

void StoreManager::PrintProducts()
{
	printf("\n--------------------------------------------------\n");
	for (int i = 0; i < storage.GetSize(); i++)
	{
		printf("Product ¹%i\n", i + 1);
		storage[i].PrintInfo();
		printf("\n");
	}
	printf("\n--------------------------------------------------\n");
}

void StoreManager::UpdateList(const List<Product>& newList)
{
	storage = newList;
	SortingByUnreturned();
}
void StoreManager::AddProduct(Product& newProduct)
{
	if (byUnreturned)
	{
		if (newProduct.returned)
			storage.Insert(newProduct, borderInd+1);
		else
			storage.Insert(newProduct, borderInd++);
	}
	else
	{
		if (!newProduct.returned)
			storage.Insert(newProduct, borderInd+1);
		else
			storage.Insert(newProduct, borderInd++);
	}
}

void StoreManager::RefreshSort()
{
	if (byUnreturned)
		SortingByReturned();
	else
		SortingByUnreturned();
}

void StoreManager::DeleteAtDate(Time& date)
{
	for (int i = 0; i < storage.GetSize(); i++)
	{
		Product* currentProduct = &storage[i];
		if (currentProduct->saleDate == date)
		{
			storage.DeleteAt(i);
			break;
		}
	}
}

void StoreManager::SortingByUnreturned()
{
	int i = borderInd;
	borderInd = 0;
	for (; i < storage.GetSize(); i++)
		if (!storage.GetNode(i)->data.returned)
		{
			borderInd++;
			storage.MoveToFront(storage.GetNode(i));
		}
	byUnreturned = true;
}

void StoreManager::SortingByReturned()
{
	int i = borderInd;
	borderInd = 0;
	for (; i < storage.GetSize(); i++)
		if (storage.GetNode(i)->data.returned)
		{
			borderInd++;
			storage.MoveToFront(storage.GetNode(i));
		}
	byUnreturned = false;
}

