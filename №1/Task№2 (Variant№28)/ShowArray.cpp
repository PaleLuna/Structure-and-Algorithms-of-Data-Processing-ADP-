#include "ShowArray.h"

void ShowArray(unsigned short* array, unsigned short len)
{
	printf("[\n");
	len--;

	//����� ������� � ������� � ��������� ���������������
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