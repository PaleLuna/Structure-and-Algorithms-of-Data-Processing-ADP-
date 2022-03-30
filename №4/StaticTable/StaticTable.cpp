#include <iostream>
#include "StudentTable.h"

using namespace std;

StudentTable table;

int main()
{
	setlocale(LC_ALL, "ru");

	unsigned count;
	printf("Введите количество студентов: ");
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		printf("\nСтудент№%i\n", i + 1);
		Student student;
		printf("Введите id: ");
		cin >> student.id;
		printf("Введите выполненные задания: ");
		for (int j = 0; j < 3; j++)
		{
			cin >> student.task[j];
		}

		if (!table.TryAdd(student)) { printf("Ошибка!"); i--; }
	}

	table.TryPrint();
	table.TryDelete(34);
	table.TryPrint();

	return 0;
}