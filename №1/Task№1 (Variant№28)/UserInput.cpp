#include "UserInput.h"

unsigned short UserInput(unsigned short min, unsigned short max)
{
	short userInput;

	while (true)
	{
		cin >> userInput;

		if (cin.fail() || ((userInput <= min) || (userInput >= max)))
		{
			printf("Ошибка! Введены некорректные данные. Повторите попытку. \n");

			cin.clear();
			cin.ignore(65535, '\n');

			continue;
		}
		break;
	}


	return userInput;
}
unsigned short UserInput()
{
	short userInput;

	while (true)
	{
		cin >> userInput;

		if (cin.fail())
		{
			printf("Ошибка! Введены некорректные данные. Повторите попытку. \n");

			cin.clear();
			cin.ignore(65535, '\n');

			continue;
		}
		break;
	}


	return userInput;
}
