#include "AutomaticFilling.h"

void AutomaticFilling(unsigned short* fillable, unsigned short len, short maxNum)
{
	//������������� ���������� ��������� �����
	srand(time(NULL));

	//���������� ������� ���������� �������
	for (int i = 0; i < len; i++)
		fillable[i] = rand() % maxNum + 1;
}