#include "ListHandler.h"

void ListHandler::SetLst(const List<int>& newLst)
{
	lst = newLst;
}
void ListHandler::FillingList()
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		lst.Push_back(rand() % 99 + 1);

	SortingLst();
}

void ListHandler::DeleteInLst(unsigned index)
{
	lst.DeleteAt(index);
}

void ListHandler::CopyInLst2()
{
	lst1 = lst;
}

void ListHandler::SortingLst()
{

}

