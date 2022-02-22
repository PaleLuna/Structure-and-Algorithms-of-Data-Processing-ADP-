#include "ShowArray.h"

void ShowArray(unsigned short* array, unsigned short len)
{

	if (len > 0)
	{
		printf("[\n");
		len--;
		//Вывод массива в консоль с некоторым форматированием
		for (unsigned short i = 0; i < len; i++)
		{
			printf("%5i,", array[i]);
			if ((i + 1) % 10 == 0)
			{
				printf("\n");
			}
		}

		printf("%5i\n]\n\n", array[len]);
	}
	else
	{
		printf("Массив пустой\n");
	}
	

}