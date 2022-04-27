#include "Stacks.h"

Stacks::Stacks(unsigned capacity)
{
    this->capacity = capacity;
    firstStackSize = 0;
    secondStackSize = 0;

    stacks = new int[capacity];
}
Stacks::~Stacks()
{
    delete[] stacks;
}

bool Stacks::Push(int data, bool firstStack)
{
    bool flag = ((firstStackSize + secondStackSize) < capacity);
    if (flag)
    {
        if (firstStack)
            PushFirst(data);
        else
            PushSecond(data);
    }

    return flag;
}
bool Stacks::Pop(int& var, bool firstStack)
{
    bool flag;
    if (firstStack)
    {
        flag = (firstStackSize > 0);
        if (flag)
            PopFirst(var);
    }
    else
    {
        flag = (secondStackSize > 0);
        if (flag)
            PopSecond(var);
    }

    return flag;
}

void Stacks::PushFirst(int data)
{
    stacks[firstStackSize++] = data;
}
void Stacks::PushSecond(int data)
{
    unsigned currentIndex = ((capacity - 1) - secondStackSize++);
    stacks[currentIndex] = data;
}

void Stacks::PopFirst(int& var)
{
    var = stacks[firstStackSize - 1];
    stacks[--firstStackSize] = 0;
}
void Stacks::PopSecond(int& var)
{
    unsigned currentIndex = (capacity - secondStackSize--);
    var = stacks[currentIndex];
    stacks[currentIndex] = 0;
}


