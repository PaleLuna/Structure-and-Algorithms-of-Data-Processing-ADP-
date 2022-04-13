#include "Input.h"
#include <fstream>
#include "List.h"

template<typename T>
void Show(List<T>& lst);

int main()
{
	setlocale(LC_ALL, "ru");
	List<int> lst;
	unsigned el;

	lst.Push_back(19);
	lst.Push_back(5);
	lst.Push_back(22);
	lst.Push_back(56);
	lst.Push_back(9);
	lst.Push_back(20);
	lst.Push_back(32);

	List<int>lst2(lst);

	Show(lst);
	Show(lst2);

	cin >> el;

	lst2.DeleteAt(el);
	Show(lst2);
	return 0;
}
template<typename T>
void Show(List<T>& lst)
{
	printf("List:\n");
		for (int i = 0; i < lst.GetSize(); i++)
			printf("%i\n", lst[i]);
	printf("\n");
}