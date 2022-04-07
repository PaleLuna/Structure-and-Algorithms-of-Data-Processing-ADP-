#include "UserInteraction.h"

bool UserInteraction::Actions(unsigned choice)
{
    bool isRun = true;

	switch (choice)
	{
		case 0:
			printf("�������...");
			isRun = false;
			break;
		case 1:
			if (!table.TryPrint()) { printf("������! ������� �� ����������������, ���� �����!\n"); }
			break;
		case 2:
			StudentInitialization();
			break;
		case 3:
			if (!table.TryAdd(CreatingStudent())) { printf("������! ������� �����������!\n"); }
			break;

		case 4:
			DeleteStudent();
			break;
	default:
		break;
	}

    return isRun;
}

void UserInteraction::StudentInitialization()
{
	unsigned count;
	printf("������� ���������� ���������: ");
	if (Input(count))
	{
		for (int i = 0; i < count; i++)
		{
			printf("\n�������%i\n", i + 1);
			if (!table.TryAdd(CreatingStudent())) { printf("������!"); i--; }
		}
	}
	else { printf("������������ ����!\n"); }

}
Student& UserInteraction::CreatingStudent()
{
	Student newStudent;

	printf("������� ID ��������: ");
	cin >> newStudent.id;
	printf("������� ����������� �������: ");
	for (int j = 0; j < 3; j++)
	{
		unsigned var;
		if (InputBool(var)) { newStudent.task[j] = var; }
		else { printf("������������ ����! ��������� ������� � ������� �%i\n", j); --j; }
	}

	return newStudent;
}
void UserInteraction::DeleteStudent()
{
	unsigned studentId;
	printf("������� ID ��������, ������� ������ ���� ������: ");
	if (Input(studentId)) { table.TryDelete(studentId); }
	else { printf("������������ ����!\n"); }
}
