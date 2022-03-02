#include <iostream>
#include <fstream>
#include "PrimesVector.h"
#include "UserInput.h"
#include "Task№3(Variant№28).h"

using namespace std;

void ShowMenu();

int main()
{
	setlocale(LC_ALL, "");
	ShowMenu();

	bool isRun = true;

	unsigned short maxLen;
	unsigned short maxNum;

	PrimesVector primesVec;


	while (isRun)
	{
		unsigned short userChoise;
		printf("Ваше действие: ");
		userChoise = UserInput(-1);

		switch (userChoise)
		{
			case 0:
				printf("Выходим...\n");
				isRun = !isRun;
				break;

			case 1:
				printf("\n");
				printf("Введите длину массива: ");
				maxLen = UserInput(0);

				printf("Введите максимально допустимое число: ");
				maxNum = UserInput(0);
				printf("\n");

				primesVec.SetVal(maxLen, maxNum);
				break;

			case 2:
				if (!primesVec.TryFillingPrimes()) { printf("Ошибка! Основной массив пуст, либо массив простых чисел уже определен!\n"); break; }
				break;

			case 3:
				if (!primesVec.TryShowSource()) { printf("Массив пустой!\n"); }
				break;

			case 4:
				if (!primesVec.TryShowPrimes()) { printf("Массив пустой!\n"); }
				break;

			case 5:
				if(primesVec.GetAmountLargeCompNums() != 0)
					printf("Количество чисел, число делителей которых больше трех: %i\n", primesVec.GetAmountLargeCompNums());
				
				else
					printf("Массив не содержит составных чисел с числом делителей больше трех, либо он пустой!\n");

				break;
			case 6:
				system("cls");
				ShowMenu();
				break;

		default:
			printf("Действите не определено. Повторите попытку.\n");
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
