#include "Input.h"
#include <fstream>
#include "List.h"

int main()
{
	setlocale(LC_ALL, "ru");
	List<int> lst;

	lst.Push_back(10);
	lst.Push_back(5);
	lst.Push_back(22);
	lst.Push_back(22);
	lst.Push_back(22);
	lst.Push_back(22);
	lst.Push_back(22);

	printf("Размерность списка: %i\n", lst.GetSize());


	return 0;
}