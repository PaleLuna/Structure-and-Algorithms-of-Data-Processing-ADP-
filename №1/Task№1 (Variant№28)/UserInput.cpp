#include "UserInput.h"

bool UserInput(unsigned short& var, short min, short max)
{
	cin >> var;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(65535, '\n');
		var = 0;
		return false;
	}

	if ((var < min) || (var > max))
	{
		var = 0;
		return false;
	}

	cin.ignore(65535, '\n');


	return true;
}
bool UserInput(unsigned short& var)
{
	cin >> var;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(65535, '\n');
		var = 0;
		return false;
	}

	cin.ignore(65535, '\n');
	
	return true;
}
