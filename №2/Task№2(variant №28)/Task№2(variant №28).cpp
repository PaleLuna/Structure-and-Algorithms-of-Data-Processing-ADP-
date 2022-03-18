#include <fstream>
#include "Input.h"
#include "DynamicMatrix.h"

DynamicMatrix dynamicMatrix;

bool isRun = true;

void ShowMenu();
void FillingArr(unsigned order);

bool ParameterInput(unsigned int& order, unsigned int& maxNum)
{
	printf("Введите порядок матрицы: ");
	if (!Input(order)) { printf("Некорректные данные!\n"); return false; }

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
		if (ParameterInput(order, maxNum)) { dynamicMatrix.SetUp(order, maxNum); break; }

	case 2:
		if (dynamicMatrix.TryShow()) { break; }
		printf("Матрица не инициализирована!\n");
		break;

	case 3:
		if (dynamicMatrix.TryTranspose()) { break; }
		printf("Матрица не инициализирована!\n");
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