#include "DynamicMatrix.h"

void DynamicMatrix::SetUp(unsigned userOrder, unsigned userMaxNum)
{
	if (orderMatrix != 0){ ClearMatrix(); } //Если матрица не пуста - очистить её
	
	//Инициализация
	orderMatrix = userOrder;
	maxNum = userMaxNum;
	dynamicMatrix = new unsigned* [orderMatrix];

	Filling();
}
void DynamicMatrix::SetUp(unsigned userOrder)
{
	if (orderMatrix != 0) { ClearMatrix(); }
	orderMatrix = userOrder;
	dynamicMatrix = new unsigned* [orderMatrix];
	ZeroFilling();
}

bool DynamicMatrix::TryShow()
{
	if (!orderMatrix) { return false; } //Если матрица пуста - вернуть false
	printf("\n\n");

	for (int i = 0; i < orderMatrix; i++)
	{
		printf("|");
		for (int j = 0; j < orderMatrix - 1; j++) { printf("%-4i", dynamicMatrix[i][j]); }
		printf("%2i|\n", dynamicMatrix[i][orderMatrix - 1]);
	}
	printf("\n\n");
	return true;
}
bool DynamicMatrix::TryTranspose()
{
	if (!orderMatrix) { return false; }

	Transpose();
	return true;
}

void DynamicMatrix::Filling()
{
	srand(time(NULL));

	for (int i = 0; i < orderMatrix; i++)
	{
		dynamicMatrix[i] = new unsigned[orderMatrix];
		for (int j = 0; j < orderMatrix; j++) { dynamicMatrix[i][j] = rand() % maxNum + 1; }
	}
}
void DynamicMatrix::ZeroFilling()
{
	for (int i = 0; i < orderMatrix; i++)
	{
		dynamicMatrix[i] = new unsigned[orderMatrix];
		for (int j = 0; j < orderMatrix; j++) { dynamicMatrix[i][j] = 0; }
	}
}
void DynamicMatrix::Add(unsigned row, unsigned col, unsigned num)
{
	dynamicMatrix[row][col] = num;
}

void DynamicMatrix::Transpose()
{
	for (int i = 0; i < orderMatrix; i++) //Цикл по строкам
		for (int j = 0; j < orderMatrix - i - 1; j++) //Цикл по столбцам выше побочной диагонали
			std::swap(dynamicMatrix[orderMatrix - j - 1][orderMatrix - i - 1], dynamicMatrix[i][j]);//Обмен значений
}

void DynamicMatrix::ClearMatrix()
{
	for (int i = 0; i < orderMatrix; i++)
		delete[] dynamicMatrix[i];
	delete[] dynamicMatrix;
}
DynamicMatrix::~DynamicMatrix()
{
	ClearMatrix();
}