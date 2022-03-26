#include <iostream>
#include "StrCopy.h"
#pragma once
class Anagrams
{
	public:
		void SetUp(char** original, unsigned size);
		bool TryShow();

		~Anagrams();
	private:
		char** source;
		unsigned amountWords = 0;

		unsigned amountPairs = 0;
		char*** anagramsPair;

		void Show();
		void InsertionSort();

		char* Reverse(char* string);
		void CrossOut(char* string);

		void WrittingWordPairs();
		bool AnagramsSearch(char* searchable, unsigned start, unsigned end);

		void ClearAnagrams();
		void ClearSource();
		void Resize();
};