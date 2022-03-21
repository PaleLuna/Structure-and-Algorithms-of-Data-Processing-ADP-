#include <iostream>
#include <string>
#include <vector>
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

		void Extractor(string inputText);
};

