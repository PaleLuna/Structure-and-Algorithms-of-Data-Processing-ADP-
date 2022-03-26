#include "StrCopy.h"

char* StrCopy(char* string)
{
	unsigned len = strlen(string) + 1;
	char* temp = new char[len];
	for (int i = 0; i < len - 1; i++)
		temp[i] = string[i];
	temp[len - 1] = '\0';

	return temp;
}
char** StrCopy(char** string, unsigned size)
{
	char** temp = new char* [size];
	for (int i = 0; i < size; i++)
	{
		unsigned len = strlen(string[i]) + 1;
		temp[i] = new char[len];

		for (int j = 0; j < len - 1; j++)
			temp[i][j] = string[i][j];
		temp[i][len - 1] = '\0';
	}
	return temp;
}