#include <iostream>
#include "StaticMatrix.h"

using namespace std;

int main()
{
	system("chcp 1251>nul");

	StaticMatrix staticMatrix;

	staticMatrix.SetUp(5);
	staticMatrix.TryShow();
	staticMatrix.TryTranspose();
	staticMatrix.TryShow();
	
	return 0;
}