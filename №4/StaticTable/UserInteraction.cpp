#include "UserInteraction.h"

bool UserInteraction::Actions(unsigned choice)
{
    bool isRun = true;

	switch (choice)
	{
		case 0:
			printf("Выходим...");
			isRun = false;
			break;
		case 1:
			if (!table.TryPrint()) { printf("Ошибка! Таблица не инициализирована, либо пуста!\n"); }
			break;
		case 2:
			StudentInitialization();
			break;
		case 3:
			if (!table.TryAdd(CreatingStudent())) { printf("Ошибка! Таблица переполнена!\n"); }
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
	printf("Введите количество студентов: ");
	if (Input(count))
	{
		for (int i = 0; i < count; i++)
		{
			printf("\nСтудент№%i\n", i + 1);
			if (!table.TryAdd(CreatingStudent())) { printf("Ошибка!"); i--; }
		}
	}
	else { printf("Некорректный ввод!\n"); }

}
Student& UserInteraction::CreatingStudent()
{
	Student newStudent;

	printf("Введите ID студента: ");
	cin >> newStudent.id;
	printf("Введите выполненные задания: ");
	for (int j = 0; j < 3; j++)
	{
		unsigned var;
		if (InputBool(var)) { newStudent.task[j] = var; }
		else { printf("Некорректный ввод! Повторите попытку с задания №%i\n", j); --j; }
	}

	return newStudent;
}
void UserInteraction::DeleteStudent()
{
	unsigned studentId;
	printf("Введите ID студента, который должен быть удален: ");
	if (Input(studentId)) { table.TryDelete(studentId); }
	else { printf("Некорректный ввод!\n"); }
}
