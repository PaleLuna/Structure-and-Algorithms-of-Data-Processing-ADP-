#include "UserInput.h"

unsigned short UserInput()
{
	short userInput;
	
	while (true)
	{
		cin >> userInput;

		if (cin.fail() || (userInput <= 0))
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