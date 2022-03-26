#include "Anagrams.h"

void Anagrams::SetUp(char** original, unsigned size)
{
	amountPairs = 0;
	ClearAnagrams();
	ClearSource();

	amountWords = size;
	source = StrCopy(original, amountWords);

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

void Anagrams::InsertionSort()
{
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
		temp[0] = StrCopy(source[i]);

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
	char* temp = StrCopy(string);

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

void Anagrams::ClearAnagrams()
{
	for (int i = 0; i < amountPairs; i++)
	{
		for (int j = 0; j < 2; j++)
			delete[] anagramsPair[i][j];
		delete[] anagramsPair[i];
	}
	delete[] anagramsPair;
}
void Anagrams::ClearSource()
{
	for (int i = 0; i < amountWords; i++)
		delete[] source[i];
	delete[] source;
}
void Anagrams::Resize()
{
	char*** temp = new char** [amountPairs];
	for (int i = 0; i < amountPairs; i++)
	{
		temp[i] = new char* [2];
		for (int j = 0; j < 2; j++)
			temp[i] = StrCopy(anagramsPair[i], 2);
	}
	ClearAnagrams();
	anagramsPair = temp;
}

Anagrams::~Anagrams()
{
	ClearAnagrams();
	ClearSource();
}