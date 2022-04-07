#include "StudentTable.h"

bool StudentTable::TryAdd(Student newStudent)
{
	bool isntFull = size < capacity-1;
	if (isntFull) { InsertingAtTheBeginning(newStudent); }
	return isntFull;
}
bool StudentTable::TryDelete(unsigned id)
{
	unsigned index = FindStudent(id);
	bool isntEmpty = (size > 0) && (index >= 0);
	if (isntEmpty) { DeleteStudent(index); }
	return isntEmpty;
}
bool StudentTable::TryPrint()
{
	bool isntEmpty = size > 0;
	if (isntEmpty) { Print(); }
	return isntEmpty;
}

void StudentTable::Print()
{
	printf("\n%9c", '\0');
	for (int i = 0; i < size; i++)
		printf("%4i", studentArray[i].id);
	printf("\n");

	unsigned taskNumber = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("%4s[%i]", "Task¹", taskNumber + 1);
		for (int j = 0; j < size; j++)
		{
			if (studentArray[j].task[taskNumber]) { printf("%4c", '+'); }
			else { printf("%4c", '-'); }
		}
		taskNumber++;
		printf("\n");
	}

	printf("%-8s", "Total");
	for (int i = 0; i < size; i++)
	{
		printf("%4i", studentArray[i].totalPoints());
	}
	printf("\n\n");
}

void StudentTable::InsertingAtTheBeginning(Student newStudent)
{
	size++;
	for (int i = size - 1; i > 0; i--)
		std::swap(studentArray[i], studentArray[i - 1]);
	studentArray[0] = newStudent;
}
void StudentTable::DeleteStudent(unsigned index)
{
	if((index + 1) != size)
	{
		for (int i = index; i < size; i++)
			studentArray[i] = studentArray[i + 1];
	}
	size--;
}
short StudentTable::FindStudent(unsigned id)
{
	for (int i = 0; i < size; i++)
		if (studentArray[i].id == id)
			return i;
	return -1;
}