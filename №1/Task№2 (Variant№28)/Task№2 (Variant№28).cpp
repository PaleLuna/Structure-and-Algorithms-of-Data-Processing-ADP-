#include <iostream>
#include <fstream>
#include "UserInput.h"
#include "DynamicSequence.h"
#include "DynamicPrimeSequence.h"

using namespace std;

DynamicSequence source;
DynamicPrimeSequence dynamicPrimeSequence;

bool isRun = true;
unsigned short sequenceLen;
unsigned short maxNum;

void ShowMenu();
void UserInteraction(unsigned short choise);
void FillingArr();

int main()
{
	system("chcp 1251>nul");

	unsigned short choise;

	ShowMenu();

	while (isRun)
	{
		printf("Ваш выбор: ");
		if (UserInput(choise))
		{
			UserInteraction(choise);
			continue;
		}
		printf("Ошибка! Введены некорректные данные, повторите попытку!\n");
	}
	printf("Выходим...\n");
	return 0;
}

void ShowMenu()
{
	ifstream menuText("MenuText.txt");
	if (menuText.is_open())
	{
		char text[1024];
		menuText.getline(text, 1024, '\0');
		printf("%s\n\n", text);
	}
}

void UserInteraction(unsigned short choise)
{
	switch (choise)
	{
	case 0:
		isRun = false;
		break;
	case 1:
		printf("Введите длину массива: ");
		if (!UserInput(sequenceLen)) { printf("Некорректные данные!\n"); break; }

		printf("Введите максимальное число в последовательности: ");
		if (!UserInput(maxNum)) { printf("Некорректные данные!\n"); break; }

		source.SetUp(sequenceLen, maxNum);
		break;

	case 2:
		FillingArr();
		break;
	case 3:
		if (source.GetSize() > 0) { dynamicPrimeSequence.SetUp(source); break; }
		printf("Ошибка вызова!\n");
		break;

	case 4:
		if (source.TryShow()) { break; }
		printf("Массив пуст!\n");
		break;

	case 5:
		if (dynamicPrimeSequence.TryShow()) { break; }
		printf("Массив пуст!\n");
		break;

	case 6:
		system("cls");
		ShowMenu();
		break;

	default:
		printf("Действие не определено.\n");
		break;
	}
}
void FillingArr()
{
	unsigned short num;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("Sequence[%i] = ", i + 1);
		if (UserInput(num))
		{
			if (num != 0) { source.Add(num); continue; }
			break;
		}
		i--;
		printf("Введены некорректные данные!\n");
	}
}
