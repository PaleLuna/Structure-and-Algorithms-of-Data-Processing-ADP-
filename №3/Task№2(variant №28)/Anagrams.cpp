#include "Anagrams.h"

void Anagrams::SetUp(char** original, unsigned size)
{
	amountPairs = 0;
	Clear();

	amountWords = size;
	source = Copy(original);

	anagramsPair = new char** [size];

	InsertionSort();
	WrittingWordPairs();
}

bool Anagrams::TryShow()
{
	bool istEmpty = amountPairs > 0;
	if (istEmpty)
	{
		Show();
	}
	return istEmpty;
}
void Anagrams::Show()
{
	for (int i = 0; i < amountPairs; i++)
	{
		printf("Пара[%i]: ", i + 1);
		printf("%s:" ,anagramsPair[i][0]);
		printf("%s;\n", anagramsPair[i][1]);
	}
}
void Anagrams::ShoWw()
{
	for (int i = 0; i < amountWords; i++)
	{
		printf("%s\n", source[i]);
	}
}


void Anagrams::InsertionSort()
{
	ShoWw();
	for (int i = 1; i < amountWords; i++)
	{
		char* tempStr = source[i];
		int j = i - 1;

		for (; j >= 0; j--)
		{
			if (strcmp(tempStr, source[j]) < 0) { source[j + 1] = source[j]; }
			else break;
		}
		source[j + 1] = tempStr;
	}
	
}

void Anagrams::WrittingWordPairs()
{
	for (int i = 0; i < amountWords; i++)
	{
		if (source[i][0] == ' ') { continue; }

		char** temp;
		temp = new char* [2];
		temp[0] = new char[strlen(source[i])];
		strcpy(temp[0], source[i]);

		char* reversed = Reverse(temp[0]);

		if (AnagramsSearch(reversed, i, amountWords - 1))
		{
			temp[1] = reversed;
			anagramsPair[amountPairs++] = temp;
		}
	}
}
char* Anagrams::Reverse(char* string)
{
	unsigned len = strlen(string);
	char* temp = new char(len);
	strcpy(temp, string);
	_strrev(temp);

	return temp;
}
bool Anagrams::AnagramsSearch(char* searchable, unsigned start, unsigned end)
{
	while (true)
	{
		unsigned mid = (start + end) / 2;

		if (strcmp(searchable, source[mid]) > 0) { start = mid + 1; }
		else if (strcmp(searchable, source[mid]) < 0) { end = mid - 1; }
		else
		{
			CrossOut(source[mid]);
			InsertionSort();
			return true;
		}

		if (start > end) { return false; }
	}
}
void Anagrams::CrossOut(char* string)
{
	string[0] = ' ';
	string[1] = '\0';
}

void Anagrams::Clear()
{
	for (int i = 0; i < amountPairs; i++)
	{
		for (int j = 0; j < 2; j++)
			delete[] anagramsPair[i][j];
		delete[] anagramsPair[i];
	}
	delete[] anagramsPair;
}
void Anagrams::Resize()
{
	char*** temp = new char** [amountPairs];
	for (int i = 0; i < amountPairs; i++)
	{
		temp[i] = new char* [2];
		for (int j = 0; j < 2; j++)
			strcpy(temp[i][j], anagramsPair[i][j]);
	}
	Clear();
	anagramsPair = temp;
}
char** Anagrams::Copy(char** original)
{
	char** temp = new char* [amountWords];
	for (int i = 0; i < amountWords; i++)
	{
		unsigned len = strlen(original[i]) + 1;
		temp[i] = new char[len];

		for (int j = 0; j < len - 1; j++)
			temp[i][j] = original[i][j];
		temp[i][len - 1] = '\0';
	}
	return temp;
}

Anagrams::~Anagrams()
{
	Clear();
}