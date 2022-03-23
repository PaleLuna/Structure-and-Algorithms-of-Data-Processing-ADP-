#include <iostream>
#pragma once

using namespace std;

class WordExtractor
{
	public:
		void SetUp(char* source);
		bool TryShow();
		char** GetWords();

		~WordExtractor();

	private:
		char* text;
		unsigned amountWords;
		char** words;

		void Show();
		unsigned GetLen(unsigned start, char* text);

		void Extractor();
		char* GetWord(unsigned start, unsigned end);
		bool IsListed(char* searchable);

		void Clear();
		void Resize();

};

