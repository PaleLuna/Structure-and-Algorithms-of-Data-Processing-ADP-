#include <iostream>
#include "StrCopy.h"
#pragma once

using namespace std;

class WordExtractor
{
	public:
		void SetUp(char* source);
		char** GetWords();
		unsigned GetSize();
		bool TryShow();

		~WordExtractor();

	private:
		char* text;
		unsigned amountWords;
		char** words;

		unsigned GetLen(unsigned start, char* text);
		void Show();

		void Extractor();
		char* GetWord(unsigned start, unsigned end);
		bool IsListed(char* searchable);

		void Clear();
		void Resize();

};

