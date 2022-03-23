#include "UserInput.h"

bool Input(unsigned& var)
{
	cin >> var;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		var = 0;
		return false;
	}
	return true;
}