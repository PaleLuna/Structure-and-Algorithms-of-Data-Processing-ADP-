#include <iostream>
#include <ctime>
#include "FindingPrimeNumbers.h"
#include "Constants.h"

using namespace std;

void AutomaticFilling(int* fillable, int len);
void ShowArray(int* array, int len);

int main()
{
	system("chcp 1251>nul");

	int source[MAX_LEN];
	int primesInSource[MAX_LEN];

	AutomaticFilling(source, MAX_LEN);
	ShowArray(source, MAX_LEN);

	FindingPrimeNumbers(source, primesInSource, MAX_LEN);

}

void AutomaticFilling(int* fillable, int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		fillable[i] = rand() % MAX_NUM + 1;
}

void ShowArray(int* array, int len)
{
	printf("[\n");
	len--;

	for (int i = 0; i < len; i++)
	{
		printf("%5i,", array[i]);
		if ((i+1) % 10 == 0)
		{
			printf("\n");
		}
	}
	
	printf("%5i\n]\n\n", array[len]);
}