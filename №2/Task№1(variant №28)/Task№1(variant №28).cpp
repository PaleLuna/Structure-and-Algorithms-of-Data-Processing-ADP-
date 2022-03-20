#include <fstream>
#include "Input.h"
#include "Constants.h"
#include "StaticMatrix.h"

StaticMatrix staticMatrix;

bool isRun = true;

void ShowMenu();
void FillingArr(unsigned order);

bool ParameterInput(unsigned& order, unsigned& maxNum)
{
	printf("Введите порядок матрицы (не больше 20!): ");
	if (!Input(order, 0, MAX_ORDER)) { printf("Некорректные данные!\n"); return false; }

	printf("Введите максимальное значение элементов: ");
	if (!Input(maxNum)) { printf("Некорректные данные!\n"); return false; }

	return true;
}
void UserInteraction(unsigned short choice)
{
	unsigned order;
	unsigned maxNum;

	switch (choice)
	{
		case 0:
			printf("Выходим...");
			isRun = false;
			break;

		case 1:
			if (ParameterInput(order, maxNum)) { staticMatrix.SetUp(order, maxNum); break; }
			break;

		case 2:
			printf("Введите порядок матрицы (не больше 20!): ");
			if (!Input(order, 0, MAX_ORDER)) { printf("Некорректные данные!\n"); break; }
			staticMatrix.SetUp(order);
			FillingArr(order);
			break;

		case 3:
			if (staticMatrix.TryShow()) { break; }
			printf("Матрица не иниализирована!\n");
			break;

		case 4:
			system("cls");
			ShowMenu();
			break;

		default:
			printf("Действие не определено.\n");
			break;
	}
}

int main()
{
	system("chcp 1251>nul");

	ShowMenu();

	while (isRun)
	{
		printf("Действие №");
		unsigned choise;
		if (Input(choise)) { UserInteraction(choise); continue; }
		printf("Некорректные данные!\n");
	}
	
	return 0;
}
void ShowMenu()
{
	std::ifstream menuText("Menu.txt");
	if (menuText.is_open())
	{
		char text[1024];
		menuText.getline(text, 1024, '\0');
		printf("%s", text);
	}
}

void FillingArr(unsigned order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			unsigned num;
			printf("matrix[%i][%i] = ", i + 1, j + 1);
			if (!Input(num)) { printf("Некорректные данные!\n"), --j; continue; }
			if (num > 0) { staticMatrix.Add(i, j, num); continue; }
			i = order;
			break;
		}
	}
}