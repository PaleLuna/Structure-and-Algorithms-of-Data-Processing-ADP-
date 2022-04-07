#include <iostream>
#include <fstream>
#include "UserInteraction.h"
#include "Input.h"

void PrintMenu();

int main()
{
	setlocale(LC_ALL, "ru");
	PrintMenu();
	UserInteraction userInteraction;
	unsigned userChoise;

	do
	{
		printf("Ваше действие: ");
		if (!Input(userChoise)) { printf("Некорректный ввод!\n"); continue; }
	} while (userInteraction.Actions(userChoise));

	return 0;
}

void PrintMenu()
{
	ifstream file("MenuText.txt");
	if (file.is_open())
	{
		char text[1024];
		file.getline(text, 1024, '\0');
		printf("%s", text);
	}
}