#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	List<Product> lst;

	lst.Push_back(Product(2, 100, Time(2, 4,2022)));
	lst.Push_back(Product(3, 150, Time(4, 4, 2022)));
	lst.Push_back(Product(4, 200, Time(6, 4, 2022), Time(7, 4, 2022)));
	lst.Push_back(Product(5, 250, Time(8, 4, 2022), Time(9, 4, 2022)));
	lst.Push_back(Product(7, 350, Time(12, 4, 2022)));
	lst.Push_back(Product(8, 400, Time(14, 4, 2022)));
	lst.Push_back(Product(9, 450, Time(16, 4, 2022), Time(17, 4, 2022)));

	for (int i = 0; i < lst.GetSize(); i++)
	{
		printf("Product №%03i\n", lst[i].productCode);
		lst[i].PrintInfo();
		printf("\n");
	}

	lst.Insert(Product(6, 300, Time(10, 4, 2022)), 4);
	printf("\n-------------------------------------------------------------------\n");
	for (int i = 0; i < lst.GetSize(); i++)
	{
		printf("Product №%03i\n", lst[i].productCode);
		lst[i].PrintInfo();
		printf("\n");
	}

	return 0;
}