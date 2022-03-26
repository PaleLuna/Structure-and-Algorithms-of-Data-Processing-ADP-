#include <fstream>
#include "WordExtractor.h"
#include "Anagrams.h"
#include "UserInput.h"

using namespace std;

bool isRun = true;

char* ReadFile();
void ShowMenu();

WordExtractor wordExtractor;
Anagrams anagrams;


void UserInteracrion(unsigned choice)
{
	char* text;
	switch (choice)
	{
	case 0:
		printf("Выходим...\n");
		isRun = false;
		break;

	case 1:
		printf("\nСчитываем...\n");
		text = ReadFile();
		printf("Готово!\n\n");

		wordExtractor.SetUp(text);
		anagrams.SetUp(wordExtractor.GetWords(), wordExtractor.GetSize());
		break;

	case 2:
		if (wordExtractor.TryShow()) { break; }
		printf("Ошибка!\n");
		break;

	case 3:
		if (anagrams.TryShow()) { break; }
		printf("Ошибка!\n");
		break;

	case 4:
		system("cls");
		ShowMenu();
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

char* ReadFile()
{
	ifstream textFile("Input.txt");
	char* text = new char[2048];

	if (textFile.is_open())
		textFile.getline(text, 2048, '\0');

	textFile.close();
	return text;
}
void ShowMenu()
{
	ifstream textFile("MainMenu.txt");

	if (textFile.is_open())
	{
		char menuText[1024];
		textFile.getline(menuText, 1024, '\0');

		printf("%s", menuText);
	}
	textFile.close();
}

