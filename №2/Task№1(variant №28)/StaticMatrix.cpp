#include "StaticMatrix.h"

void StaticMatrix::SetUp(unsigned userOrder, unsigned userMaxNum)
{
	realOrder = userOrder;
	maxNum = userMaxNum;

	GeneratingElements();
}
void StaticMatrix::SetUp(unsigned userOrder)
{
	realOrder = userOrder;
}

bool StaticMatrix::TryShow()
{
	if(!realOrder) { return false; }

	printf("\n\n\n");
	for (int i = 0; i < realOrder; i++)
	{
		printf("|");
		for (int j = 0; j < realOrder; j++)
			printf("%-4i", matrix[i][j]);
		printf("|\n");
	}
	printf("\n\n\n");
	return true;
}

void StaticMatrix::GeneratingElements()
{
	srand(time(NULL));

	for (int i = 0; i < realOrder; i++)
	{
		for (int j = 0; j < realOrder; j++)
			matrix[i][j] = rand() % maxNum + 1;
	}
}
void StaticMatrix::Add(unsigned row, unsigned col, unsigned num)
{
	unsigned temp = ((col <= row ? row : col));
	realOrder = ((realOrder <= temp ? temp+1 : realOrder));
	matrix[row][col] = num;
}