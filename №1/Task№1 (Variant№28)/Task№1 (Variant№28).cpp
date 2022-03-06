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
				staticSequence.AutoSetUp();
				break;
			
			case 2:
				printf("Значение массива должно быть в пределах [1, %i]\n", MAX_NUM);
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
