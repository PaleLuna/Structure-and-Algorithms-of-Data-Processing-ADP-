#include "Anagrams.h"

void Anagrams::SetUp(vector<string> original)
{
	source = original;
	anagrams.clear();
	anagrams.reserve(source.size());

	InsertionSorting();
	WrittingWordPairs();
}
//Сортировка вставками
void Anagrams::InsertionSorting()
{
	for (int i = 1; i < source.size(); i++)
	{
		string tempStr = source.at(i);
		int j = i - 1;

		for (; j >= 0; j--)
		{
			if (tempStr < source.at(j)) { source.at(j + 1) = source.at(j); }
			else break;
		}

		source.at(j + 1) = tempStr;
	}
}

bool Anagrams::TryShow()
{
	bool flag;
	if (anagrams.size() > 0)
	{
		flag = true;
		Show();
	}
	else flag = false;

	return flag;
}
void Anagrams::Show()
{
	for (int i = 0; i < anagrams.size(); i++)
	{
		unsigned amountWord = anagrams.at(i).size();
		printf("Пара[%i]: ", i + 1);
		for (int j = 0; j < amountWord - 1; j++) { printf("%s:", anagrams[i][j].c_str()); }
		printf("%s;\n", anagrams[i][amountWord - 1].c_str());
	}
	printf("\n");
}

void Anagrams::WrittingWordPairs()
{
	for (int i = 0; i < source.size(); i++)
	{
		if (source.at(i) == " ") { continue; }

		vector<string> temp;
		temp.reserve(2);
		temp.push_back(source.at(i));

		string reversed = source.at(i);
		reverse(reversed.begin(), reversed.end());

		if (AnagramsSearch(reversed, i, source.size() - 1))
		{
				temp.push_back(reversed);
				anagrams.push_back(temp);
		}
	}
}
//Бинарный поиск
bool Anagrams::AnagramsSearch(string searchable, unsigned start, unsigned end)
{
	while (true)
	{
		unsigned mid = (start + end) / 2;
		 
		if (searchable > source.at(mid)) { start = mid + 1; }
		else if (searchable < source.at(mid)) { end = mid - 1; }
		else 
		{
			source.at(mid) = " ";
			return true; 
		}

		if (start > end) { return false; }
	}
}