#include "StudentTable.h"

void StudentTable::Add(Student newStudent)
{
	bool isntFull = size < capacity - 1;
	if (isntFull) { Resize(); }
	InsertingAtTheBeginning(newStudent);
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
	//Вывод ID студентов
	printf("\n%9c", '\0');
	for (int i = 0; i < size; i++)
		printf("%4i", studentArray[i].id);
	printf("\n");

	//Вывод выполненных заданий
	unsigned taskNumber = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("%4s[%i]", "Task№", taskNumber + 1);
		for (int j = 0; j < size; j++)
		{
			if (studentArray[j].task[taskNumber]) { printf("%4c", '+'); }
			else { printf("%4c", '-'); }
		}
		taskNumber++;
		printf("\n");
	}

	//Вывод суммы баллов каждого студента
	printf("%-8s", "Total");
	for (int i = 0; i < size; i++)
	{
		printf("%4i", studentArray[i].totalPoints());
	}
	printf("\n\n");
}
void StudentTable::Resize()
{
	capacity += 5;
	Student* temp = new Student[capacity];
	for (int i = 0; i < size; i++)
		temp[i] = studentArray[i];
	
	delete[] studentArray;
	studentArray = temp;
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
	if ((index + 1) != size)
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

StudentTable::~StudentTable()
{
	delete[] studentArray;
}