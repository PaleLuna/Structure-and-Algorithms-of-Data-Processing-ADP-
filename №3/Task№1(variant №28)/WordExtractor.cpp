#include "WordExtractor.h"

vector<string> WordExtractor::GetText()
{
	return words;
}

void WordExtractor::SetUp(string inputText)
{
	sourceText = inputText;
	words.clear();
	words.reserve(1000);
	Extractor();
}
bool WordExtractor::TryShowText()
{
	if (words.size() == 0) { return false; }

	for (int i = 0; i < words.size(); i++)
	{
		printf("Word[%i]: %s\n", i+1, words.at(i).c_str());
	}
	printf("\n");
}

void WordExtractor::Extractor()
{
	for (int i = 0; i < sourceText.size(); i++)
	{
		if (sourceText.at(i) != ' ')
		{
			int j = sourceText.find(' ', i);
			if(j < 0){j = sourceText.size();}

			string word = GetWord(i, j);
			if(!IsListed(word)){ words.push_back(GetWord(i, j)); }
			i = j;
		}
	}
	words.reserve(words.size());
}
string WordExtractor::GetWord(unsigned start, unsigned end)
{
	string word;
	word.reserve(end - start);

	for (int i = start; i < end; i++)
		if (!binary_search(separators.begin(), separators.end(), sourceText.at(i)))
			word.push_back(sourceText.at(i));

	return word;
}

bool WordExtractor::IsListed(string searchable)
{
	for (string& x : words) { if (x == searchable) return true; }
	return false;
}