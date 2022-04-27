#include "Stack.h"

Stack::Stack(unsigned capacity)
{
	this->capacity = capacity;
	size = 0;

	stack = new int[capacity];
}

Stack::~Stack()
{
	delete[] stack;
}

bool Stack::Push(int var)
{
	bool flag = size < capacity;
	if (flag)
		stack[size++] = var;

	return flag;
}

bool Stack::Pop(int& var)
{
	bool flag = !IsEmpty();
	if (flag)
	{
		var = stack[size - 1];
		stack[--size] = 0;
	}

	return flag;
}

bool Stack::GetHead(int& var)
{
	bool flag = !IsEmpty();
	if (flag)
		var = stack[size - 1];
	return false;
}

bool Stack::IsEmpty()
{
	bool isEmpty = size == 0;
	return isEmpty;
}

void Stack::Clear()
{
	while (size > 0)
		stack[--size] = 0;
}
