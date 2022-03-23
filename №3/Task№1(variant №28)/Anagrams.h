#include <iostream>
#include <vector>
#include <string>
#pragma once

using namespace std;

class Anagrams
{
	public:
		void SetUp(vector<string> original);
		bool TryShow();

	private:
		vector<vector<string>> anagrams;
		vector<string> source;

		void Show();
		void InsertionSorting();

		void WrittingWordPairs();
		bool AnagramsSearch(string searchable, unsigned start, unsigned end);
};

