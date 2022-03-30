#include "WordExtractor.h"

char** WordExtractor::GetWords()
{
	if (amountWords > 0) { return words; }
}
unsigned WordExtractor::GetSize()
{
	return amountWords;
}

void WordExtractor::SetUp(char* original)
{
	source = original;
	Clear();
	words = new char*[512];

	Extractor();
}
bool WordExtractor::TryShow()
{
	bool istEmpty = amountWords > 0;
	if (istEmpty)
		Show();
	return istEmpty;
}

void WordExtractor::Show()
{
	for (int i = 0; i < amountWords; i++)
		printf("Word[%i]: %s\n", i + 1, words[i]);
}

void WordExtractor::Extractor()
{
	for (int i = 0; source[i]; i++)
	{
		if (source[i] != ' ')
		{
			int j = GetLen(i, source);

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
		word[len++] = source[i];
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
	char** temp = StrCopy(words, amountWords);

	Clear();
	words = temp;
}

WordExtractor::~WordExtractor()
{
	Clear();
}