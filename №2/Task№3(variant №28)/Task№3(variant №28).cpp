#include <fstream>
#include "Input.h"
#include "SetOfPoints.h"

SetOfPoints setOfPoints;

bool isRun = true;

void ShowMenu();
void FillingArr(unsigned amountPoints);

bool ParameterInput(unsigned int& val)
{
	printf("Введите количество точек: ");
	return Input(val);
}
void UserInteraction(unsigned short choice)
{
	unsigned inputAmountPoints;

	switch (choice)
	{
	case 0:
		printf("Выходим...");
		isRun = false;
		break;

	case 1:
		if (ParameterInput(inputAmountPoints)) 
		{
			setOfPoints.SetUp(inputAmountPoints);
			FillingArr(inputAmountPoints);
		}
		else printf("Некорректные данные.\n");
		break;

	case 2:
		if (setOfPoints.TryShow()) { break; }
		printf("Ошибка! Точки не заданы.\n");
		break;

	case 3:
		printf("Горизонтальная медиана x = %0.2f\n", setOfPoints.GetMedian());
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

void FillingArr(unsigned amountPoints)
{
	vector<unsigned> coord;
	coord.resize(setOfPoints.GetAmountCoords());

	for (int i = 0; i < amountPoints; i++)
	{
		printf("Введите координаты точки №%i: ", i + 1);
		for (int j = 0; j < setOfPoints.GetAmountCoords(); j++)
		{
			if (Input(coord.at(j))) { continue; }
			j--;
		}

		if(!setOfPoints.TryAddPoint(coord))
		{
			printf("Точки не должны лежать на одной прямой!\n");
			i--;
		}
	}
}