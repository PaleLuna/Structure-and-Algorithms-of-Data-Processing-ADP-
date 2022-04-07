#include <iostream>
#include "Student.h"
#pragma once

class StudentTable
{
	public:
		void Add(Student newStudent);
		bool TryDelete(unsigned id);
		bool TryPrint();

		~StudentTable();
	private:
		unsigned capacity = 10;
		unsigned size = 0;
		Student* studentArray;

		void Print();
		void Resize();

		void InsertingAtTheBeginning(Student newStudent);
		void DeleteStudent(unsigned index);
		short FindStudent(unsigned id);
};

