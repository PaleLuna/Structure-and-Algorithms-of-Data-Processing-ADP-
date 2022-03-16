#include "StaticMatrix.h"

void StaticMatrix::SetUp(unsigned userOrder, unsigned userMaxNum)
{
	realOrder = userOrder;
	maxNum = userMaxNum;

	Filling();
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
bool StaticMatrix::TryTranspose()
{
	if(!realOrder) { return false; }

	Transpose();
	return true;
}

void StaticMatrix::Filling()
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

void StaticMatrix::Transpose()
{
	for (int i = 0; i < realOrder; i++) //Цикл по строкам
		for (int j = 0; j < realOrder - i - 1; j++) //Цикл по столбцам выше побочной диагонали
			//Обмен значений
			std::swap(matrix[realOrder - j - 1][realOrder - i - 1], matrix[i][j]);
}