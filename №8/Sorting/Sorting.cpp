#include <iostream>

using namespace std;

void Print(int* array, unsigned size);
void QSort(int* array, unsigned start, unsigned end);
void AutoFilling(int* array, unsigned size);
void ManualFilling(int* array, unsigned size);

int main()
{
	setlocale(LC_ALL, "ru");

	unsigned size;
	int* array;

	printf("Введите размер массива: ");
	cin >> size;
	array = new int[size];

	char c;
	printf("Заполнить массив автоматически? Y/N: ");
	cin >> c;
	if ((char)toupper(c) == 'Y')
	{
		AutoFilling(array, size);
	}
	else
	{
		ManualFilling(array, size);
	}
	printf("Массив до сортировки -> ");
	Print(array, size-1);
	printf("\nМассив после сортировки -> ");
	Print(array, size-1);

	return 0;
}

void Print(int* array, unsigned size)
{
	if (size > 0)
		Print(array, size - 1);
	printf(" %i", array[size]);
}

void ManualFilling(int* array, unsigned size)
{
	for (int i = 0; i < size; i++)
	{
		printf("array[%i] = ", i + 1);
		cin >> array[i];
	}
}
void AutoFilling(int* array, unsigned size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		array[i] = rand() % 99 + 1;
}

void QSort(int* array, unsigned start, unsigned end)
{
	unsigned pointerLeft = start;
	unsigned pointerRight = end-1;
	unsigned mid = (start + end) / 2;

	while (pointerLeft <= pointerRight)
	{
		//
	}
}