#include <iostream>
#include "Stacks.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Stacks stacks(6);

	stacks.Push(1, 1);
	stacks.Push(2, 1);
	stacks.Push(3, 1);
	stacks.Push(10, 0);
	stacks.Push(11, 0);
	stacks.Push(12, 0);

	int var;
	printf("First Stack: ");
	while (true)
	{
		if (stacks.Pop(var, 1))
			printf("%i ", var);
		else
			break;
	}
	printf("\nSecond Stack: ");
	while (true)
	{
		if (stacks.Pop(var, 0))
			printf("%i ", var);
		else
			break;
	}

	return 0;
}