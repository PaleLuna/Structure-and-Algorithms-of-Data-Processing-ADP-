#include "UserInteraction.h"

bool UserInteracrion(unsigned choice)
{
    bool isRun = true;

	switch (choice)
	{
		case 0:
			printf("�������...");
			isRun = false;
			break;
		case 1:
			break;
		case 2:
			StudentInitialization();
			break;
		case 3:
			if (!table.TryAdd(CreatingStudent())) { printf("������!"); }
			break;
		case 4:
			DeleteStudent();
			break;
		case 5:
			break;
	default:
		break;
	}

    return isRun;
}
void StudentInitialization()
{
	unsigned count;
	printf("������� ���������� ���������: ");
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		printf("\n�������%i\n", i + 1);
		if (!table.TryAdd(CreatingStudent())) { printf("������!"); i--; }
	}
}
Student& CreatingStudent()
{
	Student newStudent;

	printf("������� id: ");
	cin >> newStudent.id;
	printf("������� ����������� �������: ");
	for (int j = 0; j < 3; j++)
	{
		cin >> newStudent.task[j];
	}

	return newStudent;
}
