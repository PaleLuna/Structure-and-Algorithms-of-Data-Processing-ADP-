#include "ListHandler.h"

void ListHandler::PrintLists()
{
	printf("Origin List: ");
	for (int i = 0; i < originList.GetSize(); i++)
		printf("%i ", originList[i]);

	printf("\nCopy List: ");
	for (int i = 0; i < copyList.GetSize(); i++)
		printf("%i ", copyList[i]);
	printf("\n");
}

void ListHandler::CreateList(unsigned size)
{
	if (originList.GetSize() > 0)
		originList.Clear();

	srand(time(NULL));

	for (int i = 0; i < size; i++)
		originList.Push_back((rand() % 99) + 1);
	SortingOrigin();
}
void ListHandler::SortingOrigin()
{
	for (unsigned step = originList.GetSize() / 2; step > 0; step /= 2)
		for (int i = step; i < originList.GetSize(); i++)
			for (int j = i - step; (j >= 0) && (GetHighDigit(originList[j]) > GetHighDigit(originList[j + step])); j -= step)
				std::swap(originList[j], originList[j + step]);	
}

void ListHandler::CopyLst()
{
	copyList = originList;
	SortingCopy();
}
void ListHandler::SortingCopy()
{
	for (unsigned step = copyList.GetSize() / 2; step > 0; step /= 2)
		for (int i = step; i < copyList.GetSize(); i++)
			for (int j = i - step; (j >= 0) && (GetLowDigit(copyList[j]) > GetLowDigit(copyList[j + step])); j -= step)
			{
				std::swap(copyList[j], copyList[j + step]);
				DeleteInOriginal(j);
				DeleteInOriginal(j + step);
			}	
}
void ListHandler::DeleteInOriginal(int data)
{
	unsigned indexToDelete = originList.Find(copyList[data]);
	if (indexToDelete < originList.GetSize())
		originList.DeleteAt(indexToDelete);
}

bool ListHandler::IsSorted()
{
	bool isSorted = true;
	for (int i = 0; (i < (copyList.GetSize()) - 1) && isSorted; i++)
		isSorted = GetLowDigit(copyList[i]) <= GetLowDigit(copyList[i + 1]);
	return isSorted;
}

int ListHandler::GetHighDigit(int var)
{
	int highDigit = var / 10;
	if (highDigit == 0)
		highDigit = var;
		
	return highDigit;
}
int ListHandler::GetLowDigit(int var)
{
	return var % 10;
}