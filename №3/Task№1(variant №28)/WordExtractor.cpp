#include "WordExtractor.h"

void WordExtractor::SetUp(string inputText)
{
	Extractor(inputText);
}
bool WordExtractor::TryShowText()
{
	if (words.size() == 0) { return false; }

	for (int i = 0; i < words.size(); i++)
	{
		printf("%s ", words.at(i).c_str());
	}
}

vector<string> WordExtractor::GetText()
{
	return words;
}

void WordExtractor::Extractor(string inputText)
{
	for (int i = 0; i < inputText.size(); i++)
	{
		if (inputText.at(i) != ' ')
		{
			int j = inputText.find(' ');
		}
		continue;
	}
}

