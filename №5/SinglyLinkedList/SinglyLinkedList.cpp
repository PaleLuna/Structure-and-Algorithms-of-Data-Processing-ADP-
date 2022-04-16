#include "Input.h"
#include <fstream>
#include "ListHandler.h"

int main()
{
	setlocale(LC_ALL, "ru");
	ListHandler lstHandler;

	lstHandler.CreateList(10);
	lstHandler.CopyLst();
	lstHandler.PrintLists();

	if (lstHandler.IsSorted())
		printf("Sorted!\n");
	else
		printf("Isn't sorted!\n");

	system("pause");
	return 0;
}
