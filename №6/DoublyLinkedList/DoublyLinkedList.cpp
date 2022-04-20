#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	List<int> lst;

	lst.Push_back(2);
	lst.Push_back(3);
	lst.Push_back(8);
	lst.Push_back(1);
	lst.Push_back(9);
	lst.Push_back(0);
	lst.Push_back(21);

	List<int> lst1;
	lst1 = lst;

	printf("List1:\n");
	for (int i = 0; i < lst.GetSize(); i++)
		printf("%i ", lst[i]);
	printf("\nList2:\n");
	for (int i = 0; i < lst1.GetSize(); i++)
		printf("%i ", lst1[i]);

	lst1.Clear();
	printf("\nList1:\n");
	for (int i = 0; i < lst.GetSize(); i++)
		printf("%i ", lst[i]);
	printf("\nList2:\n");
	for (int i = 0; i < lst1.GetSize(); i++)
		printf("%i ", lst1[i]);


	return 0;
}