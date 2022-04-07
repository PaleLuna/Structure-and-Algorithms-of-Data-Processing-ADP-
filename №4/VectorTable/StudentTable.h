#include <iostream>
#include <vector>
#include "Student.h"
#pragma once

using namespace std;


class StudentTable
{
public:
	void Add(Student newStudent);
	bool TryDelete(unsigned id);
	bool TryPrint();

private:
	vector<Student> studentArray;

	void Print();

	void InsertingAtTheBeginning(Student newStudent);
	void DeleteStudent(unsigned index);
	short FindStudent(unsigned id);
};

