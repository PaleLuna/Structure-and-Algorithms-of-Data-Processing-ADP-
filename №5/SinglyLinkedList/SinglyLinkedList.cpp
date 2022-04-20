#include "ListHandler.h"

int main()
{
	setlocale(LC_ALL, "ru");
	ListHandler lstHandler;

	unsigned size;
	printf("Введите количество элементов в списке: ");
	cin >> size;

	lstHandler.CreateList(size);
	lstHandler.CopyLst();
	lstHandler.PrintLists();

	if (lstHandler.IsSorted())
		printf("Sorted!\n");
	else
		printf("Isn't sorted!\n");

	system("pause");
	return 0;
}