#include <iostream>
#include "ListStack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	ListStack<int> stack;

	stack.Push(97);
	stack.Push(34);
	stack.Push(10);
	stack.Push(29);
	stack.Push(1);
	stack.Push(53);
	stack.Push(3);
	stack.Push(2);

	int var;
	while (stack.Pop(var))
		printf("%i\n", var);

	return 0;
}