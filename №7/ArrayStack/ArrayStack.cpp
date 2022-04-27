#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Stack stack;
	stack.Push(20);
	stack.Push(1);
	stack.Push(25);
	stack.Push(4);
	stack.Push(2);
	stack.Push(1);

	int var;
	while (stack.Pop(var))
	{
		printf("%i\n", var);
	}

	return 0;
}