#include "UserInput.h"

unsigned short UserInput(short min, short max)
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

		if ((userInput < min) || (userInput > max))
		{
			printf("Число не входит в заданный диапазон!\n");
			continue;
		}
		cin.ignore(65535, '\n');
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
		cin.ignore(65535, '\n');
		break;
	}


	return userInput;
}
