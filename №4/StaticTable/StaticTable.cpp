#include <iostream>
#include <fstream>

using namespace std;

void PrintMenu();

int main()
{
	setlocale(LC_ALL, "ru");
	PrintMenu();

	table.TryPrint();
	table.TryDelete(34);
	table.TryPrint();

	return 0;
}

void PrintMenu()
{
	ifstream file("MenuText.txt");
	if (file.is_open())
	{
		char text[1024];
		file.getline(text, 1024, '\0');
		printf("%s", text);
	}
}