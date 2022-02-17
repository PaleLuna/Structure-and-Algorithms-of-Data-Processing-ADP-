#include <iostream>
#include <ctime>

using namespace std;

const int MAX_LEN = 100;

void AutomaticFilling(int* fillable, int len);
void ShowArray(int* array, int len);

int main()
{

	int source[MAX_LEN];
	int arrayOfPrimes[MAX_LEN];

	AutomaticFilling(source, MAX_LEN);
	ShowArray(source, MAX_LEN);

}

void AutomaticFilling(int* fillable, int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		fillable[i] = rand() % 100 + 1;
}

void ShowArray(int* array, int len)
{
	printf("[\n");
	len--;

	for (int i = 0; i < len; i++)
	{
		printf("%5i,", array[i]);
		if ((i > 0) && (i % 10 == 0)) printf("\n");
	}
	
	printf("%5i\n]");
}