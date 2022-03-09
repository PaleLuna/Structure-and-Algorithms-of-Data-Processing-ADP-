#include <iostream>
#include <fstream>
#include "UserInput.h"
#include "StaticSequence.h"
#include "StaticPrimeSequence.h"

using namespace std;

StaticSequence staticSequence;
StaticPrimeSequence staticPrimeSequence;

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
			printf("Введите длину массива в пределах [1, %i]: ", MAX_SIZE);
			if (!UserInput(sequenceLen, 1, MAX_SIZE)) { printf("Некорректные данные!\n"); break; }

			printf("Введите максимальное число в последовательности в пределах [2, %i]: ", MAX_NUM);
			if (!UserInput(maxNum, 2, MAX_NUM)) { printf("Некорректные данные!\n"); break; }

			staticSequence.SetUp(sequenceLen, maxNum);
			break;

		case 2:
			printf("Вводимые числа должны быть в диапазоне [1, %i], а их количество  не более %i\n", MAX_NUM, MAX_SIZE);
			FillingArr();
			break;
		case 3:
			if (staticSequence.GetLen() > 0) { staticPrimeSequence.FillingPrimeSeq(staticSequence); break; }
			printf("Ошибка вызова!\n");
			break;

		case 4:
			if (staticSequence.TryShow()) { break; }
			printf("Массив пуст!\n");
			break;

		case 5:
			if (staticPrimeSequence.TryShow()) { break; }
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
		if (UserInput(num, 0, MAX_NUM))
		{
			if (num != 0) { staticSequence.Add(num); continue; }
			break;
		}
		i--;
		printf("Введены некорректные данные!\n");
	}
}
