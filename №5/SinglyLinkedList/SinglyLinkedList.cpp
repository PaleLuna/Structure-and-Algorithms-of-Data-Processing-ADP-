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

	lstHandler.PrintLists();

	return 0;
}
