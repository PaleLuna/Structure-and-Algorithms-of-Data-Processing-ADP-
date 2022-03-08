#include <iostream>
#include <fstream>
#include "UserInput.h"
#include "StaticSequence.h"

using namespace std;

void ShowMenu();

int main()
{
	system("chcp 1251>nul");

	StaticSequence staticSequence;
	
	bool isRun = true;
	short choise;

	unsigned short sequenceLen;
	unsigned short maxNum;

	ShowMenu();

	while (isRun)
	{
		printf("Действие№ ");
		choise = UserInput();

		switch (choise)
		{
			case 0:
				printf("Выходим...\n");
				isRun = false;
				break;

			case 1:
				printf("Введите длину массива в пределах [1, %i]: ", MAX_SIZE);
				sequenceLen = UserInput(1, MAX_SIZE);
				printf("Введите максимальное число в последовательности в пределах [2, %i]: ", MAX_NUM);
				maxNum = UserInput(2, MAX_NUM);

				staticSequence.SetUp(sequenceLen, maxNum);
				break;
			
			case 2:
				printf("Вводимые числа должны быть в диапазоне [1, %i], а их количество  не более %i\n", MAX_NUM, MAX_SIZE);

				staticSequence.SetUp();
				break;

			case 3:
				if (staticSequence.TryShowSource()) { break; }
				printf("Массив пуст!\n");
				break;

			case 4:
				if (staticSequence.TryShowPrimes()) { break; }
				printf("Массив пуст!\n");
				break;

			case 5:
				system("cls");
				ShowMenu();
				break;

			default:
				printf("Действие не определено.\n");
				break;
		}
	}

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
