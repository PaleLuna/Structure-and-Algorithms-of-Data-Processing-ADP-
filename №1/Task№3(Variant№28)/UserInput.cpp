#include "UserInput.h"

unsigned short UserInput(short min)
{
	short userInput;

	while (true)
	{
		cin >> userInput;

		if (cin.fail() || (userInput <= min))
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