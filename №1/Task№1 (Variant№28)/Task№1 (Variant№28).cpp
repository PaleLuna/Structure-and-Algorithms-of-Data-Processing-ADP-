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

	//Объявление
	int amountPrimesInSource; //Количество простых чисел
	int source[MAX_LEN]; //Основной массив
	int primesInSource[MAX_LEN]; //свободный массив основанный на простых числах из основного

	//Заполнение основного массива и его вывод в консоль
	printf("Основной массив целых чисел:\n");
	AutomaticFilling(source, MAX_LEN);
	ShowArray(source, MAX_LEN);

	//Заполнение свободного массива простыми числами и его вывод в консоль
	printf("Простые числа из основного массива целых чисел:\n");
	FindingPrimeNumbers(source, primesInSource, amountPrimesInSource);
	ShowArray(primesInSource, amountPrimesInSource);
}

void AutomaticFilling(int* fillable, int len)
{
	//Инициадизация генератора случайных чисел
	srand(time(NULL));

	//Заполнение массива случайными числами
	for (int i = 0; i < len; i++)
		fillable[i] = rand() % MAX_NUM + 1;
}

void ShowArray(int* array, int len)
{
	printf("[\n");
	len--;

	//Вывод массива в консоль с некоторым форматированием
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