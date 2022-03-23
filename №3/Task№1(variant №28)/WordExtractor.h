#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#pragma once

using namespace std;

class WordExtractor
{
	public:
		void SetUp(string inputText);
		bool TryShowText();
		vector<string> GetText();

	private:
		vector<string> words;
		string sourceText;
		vector<char> separators = { '\t','\n','!',',', '.',':', ';', '?'};

		void Extractor();
		string GetWord(unsigned start, unsigned end);
		bool IsListed(string searchable);
};

