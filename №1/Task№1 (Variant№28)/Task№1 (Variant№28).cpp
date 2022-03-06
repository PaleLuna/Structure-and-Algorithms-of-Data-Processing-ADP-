#include <iostream>
#include "StaticSequence.h"

int main()
{
	system("chcp 1251>nul");

	StaticSequence staticSequence;
	
	staticSequence.SetUp();

	staticSequence.TryShowSource();

	return 0;
}