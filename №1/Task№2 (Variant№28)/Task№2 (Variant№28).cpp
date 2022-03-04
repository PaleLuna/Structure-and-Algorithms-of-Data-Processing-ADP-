#include <iostream>
#include <fstream>
#include "SequencePrimeNumbers.h"
#include "UserInput.h"

using namespace std;

void ShowMenu();

int main()
{
	system("chcp 1251>nul");

	ShowMenu();

	bool isRun = true;

	unsigned short maxLen;
	unsigned short maxNum;

	SequencePrimeNumbers seqPrimes;

	unsigned short choise;

	while(isRun)
	{
		printf("Действие№ ");
		choise = UserInput();

		switch (choise)
		{
			case 0:
				isRun = !isRun;
				printf("Выходим...\n");
				break;

			case 1:
				printf("Введите длину массива: ");
				maxLen = UserInput(0);
				printf("Введите максимально допустимое число: ");
				maxNum = UserInput(0);

				seqPrimes.SetUp(maxLen, maxNum);
				break;

			case 2:
				if (seqPrimes.TryShowSource()) { break; }
				printf("Ошибка! Массив не инициализирован!\n");
				break;

			case 3:
				if (seqPrimes.TryShowPrimes()) { break; }
				printf("Ошибка! Массив не инициализирован или пуст!\n");
				break;

			case 4:
				--seqPrimes;
				break;

			case 5:
				system("cls");
				ShowMenu();
				break;

			default:
				printf("Действие не определено. Повторите попытку!\n");
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