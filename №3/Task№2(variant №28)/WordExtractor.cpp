#include "WordExtractor.h"

char** WordExtractor::GetWords()
{
	if (amountWords > 0) { return words; }
}

void WordExtractor::SetUp(char* source)
{
	text = source;
	Clear();
	words = new char*[512];

	Extractor();
}
bool WordExtractor::TryShow()
{
	bool flag;
	if (amountWords > 0)
	{
		flag = true;
		Show();
	}
	else flag = false;

	return flag;
}
void WordExtractor::Show()
{
	for (int i = 0; i < amountWords; i++)
	{
		printf("Word[%i]: %s\n", i + 1, words[i]);
	}
	printf("\n");
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
	amountWords--;
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
	bool flag = false;
	for (int i = 0; i < amountWords; i++)
	{
		if (words[i] == searchable)
		{
			flag = true;
			break;
		}
	}
	return flag;
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
		unsigned len = GetLen(0, words[i]);
		temp[i] = new char [len++];
		for(int j = 0; j < len - 1; j++)
			temp[i][j] = words[i][j];
		temp[i][len - 1] = '\0';
	}

	Clear();
	words = temp;
}

WordExtractor::~WordExtractor()
{
	Clear();
}