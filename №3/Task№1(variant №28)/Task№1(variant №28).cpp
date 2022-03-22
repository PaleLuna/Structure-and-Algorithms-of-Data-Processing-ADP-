#include <fstream>
#include <string>
#include "WordExtractor.h"
#include "UserInput.h"

using namespace std;

bool isRun = true;

void ReadFile(string& text);
void ShowMenu();

WordExtractor wordExtractor;

void UserInteracrion(unsigned choice)
{
	string text;
	switch (choice)
	{
		case 0:
			printf("Выходим...\n");
			isRun = false;
			break;

		case 1:
			printf("\nСчитываем...\n");
			ReadFile(text);
			printf("Готово!\n\n");
			wordExtractor.SetUp(text);
			break;

		case 2:
			if (wordExtractor.TryShowText()) { break; }
			printf("Файл пуст или не считан!\n");
			break;

		default:
			printf("Действие не опеределено.\n");
			break;
	}
}

int main()
{
	system("chcp 1251>nul");
	ShowMenu();

	unsigned choice;
	while (isRun)
	{
		printf("Действие №");
		if (!Input(choice))
		{
			printf("Некорректные данные!\n");
			continue;
		}
		UserInteracrion(choice);
	}	
}

void ReadFile(string& text)
{
	ifstream textFile("Input.txt");

	if (textFile.is_open())
		getline(textFile, text, '\0');

	textFile.close();
}
void ShowMenu()
{
	string menuText;
	ifstream textFile("MainMenu.txt");

	if (textFile.is_open())
	{
		getline(textFile, menuText, '\0');

		printf("%s", menuText.c_str());
	}
	textFile.close();
}

