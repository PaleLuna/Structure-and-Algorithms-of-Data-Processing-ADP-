#include "UserInteraction.h"

bool UserInteracrion(unsigned choice)
{
    bool isRun = true;

	switch (choice)
	{
		case 0:
			printf("Выходим...");
			isRun = false;
			break;
		case 1:
			break;
		case 2:
			StudentInitialization();
			break;
		case 3:
			if (!table.TryAdd(CreatingStudent())) { printf("Ошибка!"); }
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
	printf("Введите количество студентов: ");
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		printf("\nСтудент№%i\n", i + 1);
		if (!table.TryAdd(CreatingStudent())) { printf("Ошибка!"); i--; }
	}
}
Student& CreatingStudent()
{
	Student newStudent;

	printf("Введите id: ");
	cin >> newStudent.id;
	printf("Введите выполненные задания: ");
	for (int j = 0; j < 3; j++)
	{
		cin >> newStudent.task[j];
	}

	return newStudent;
}
