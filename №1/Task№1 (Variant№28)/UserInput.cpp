#include "UserInput.h"

unsigned short UserInput(int limit)
{
	short userInput;

	while (true)
	{
		cin >> userInput;

		if (cin.fail() || (userInput <= limit))
		{
			printf("������! ������� ������������ ������. ��������� �������. \n");

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
			printf("������! ������� ������������ ������. ��������� �������. \n");

			cin.clear();
			cin.ignore(65535, '\n');

			continue;
		}
		break;
	}


	return userInput;
}
