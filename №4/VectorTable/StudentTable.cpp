#include "StudentTable.h"

void StudentTable::Add(Student newStudent)
{
	InsertingAtTheBeginning(newStudent);
}
bool StudentTable::TryDelete(unsigned id)
{
	unsigned index = FindStudent(id);
	bool isntEmpty = (studentArray.size() > 0) && (index >= 0);
	if (isntEmpty) { DeleteStudent(index); }
	return isntEmpty;
}
bool StudentTable::TryPrint()
{
	bool isntEmpty = studentArray.size() > 0;
	if (isntEmpty) { Print(); }
	return isntEmpty;
}

void StudentTable::Print()
{
	//Вывод ID студентов
	printf("\n%9c", '\0');
	for (int i = 0; i < studentArray.size(); i++)
		printf("%4i", studentArray[i].id);
	printf("\n");

	//Вывод выполненных заданий
	unsigned taskNumber = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("%4s[%i]", "Task№", taskNumber + 1);
		for (int j = 0; j < studentArray.size(); j++)
		{
			if (studentArray[j].task[taskNumber]) { printf("%4c", '+'); }
			else { printf("%4c", '-'); }
		}
		taskNumber++;
		printf("\n");
	}

	//Вывод суммы баллов каждого студента
	printf("%-8s", "Total");
	for (int i = 0; i < studentArray.size(); i++)
	{
		printf("%4i", studentArray[i].totalPoints());
	}
	printf("\n\n");
}

void StudentTable::InsertingAtTheBeginning(Student newStudent)
{
	studentArray.insert(studentArray.begin(), newStudent);
}
void StudentTable::DeleteStudent(unsigned index)
{
	studentArray.erase(studentArray.begin() + index);
}
short StudentTable::FindStudent(unsigned id)
{
	for (int i = 0; i < studentArray.size(); i++)
		if (studentArray[i].id == id)
			return i;
	return -1;
}