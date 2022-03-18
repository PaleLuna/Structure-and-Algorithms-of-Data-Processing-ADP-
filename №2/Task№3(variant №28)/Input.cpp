#include "Input.h"

bool Input(unsigned& var, unsigned min, unsigned max)
{
	cin >> var;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(2048, '\n');
		return false;
	}
	if ((var >= min) && (var < max)) { return true; }
	return false;
}
bool Input(unsigned& var)
{
	cin >> var;

	if (cin.fail() || var < 0)
	{
		cin.clear();
		cin.ignore(2048, '\n');
		return false;
	}
	return true;
}