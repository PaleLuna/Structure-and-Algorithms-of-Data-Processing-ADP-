#include "StaticMatrix.h"
#include "StaticMatrix.h"

void StaticMatrix::SetUp(unsigned userOrder)
{
	realOrder = userOrder;

	Filling();
}

bool StaticMatrix::TryShow()
{
	if(!realOrder) { return false; }

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
			matrix[i][j] = rand() % MAX_NUM + 1;
	}
}

void StaticMatrix::Transpose()
{
	for (int i = 0; i < realOrder; i++) //Цикл по строкам
		for (int j = 0; j < realOrder - i - 1; j++) //Цикл по столбцам выше побочной диагонали
			//Обмен значений
			std::swap(matrix[realOrder - j - 1][realOrder - i - 1], matrix[i][j]);
}
