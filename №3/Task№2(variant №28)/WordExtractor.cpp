#include "WordExtractor.h"

char** WordExtractor::GetWords()
{
	if (amountWords > 0) { return words; }
}
unsigned WordExtractor::GetSize()
{
	return amountWords;
}

void WordExtractor::SetUp(char* source)
{
	text = source;
	Clear();
	words = new char*[512];

	Extractor();
}

void WordExtractor::Extractor()
{
	for (int i = 0; text[i]; i++)
	{
		if (text[i] != ' ')
		{
			int j = GetLen(i, text);

			char* word = GetWord(i, j);
			if (!IsListed(word)) { words[amountWords++] = word; }
			i = j;
		}
	}
	Resize();
}
unsigned WordExtractor::GetLen(unsigned start, char* text)
{
	int str = start;
	for (; text[str]; str++)
		if (text[str] == ' ') break;

	return str;
}
char* WordExtractor::GetWord(unsigned start, unsigned end)
{
	unsigned len = 0;
	char* word = new char[(end - start) + 1];

	for (int i = start; i < end; i++)
		word[len++] = text[i];
	word[len++] = '\0';

	return word;
}
bool WordExtractor::IsListed(char* searchable)
{
	bool isListed = false;
	for(int i = 0; i < amountWords; i++)
		if (strcmp(searchable, words[i]) == 0)
		{
			isListed = true;
			break;
		}

	return isListed;
}

void WordExtractor::Clear()
{
	if (amountWords > 0)
	{
		for (int i = 0; i < amountWords; i++)
			delete[] words[i];
		delete[] words;
	}
}
void WordExtractor::Resize()
{
	char** temp = new char* [amountWords];
	for (int i = 0; i < amountWords; i++)
	{
		unsigned len = strlen(words[i]) + 1;
		temp[i] = new char [len];
		strcpy(temp[i], words[i]);
	}

	Clear();
	words = temp;
}

WordExtractor::~WordExtractor()
{
	//Clear();
}