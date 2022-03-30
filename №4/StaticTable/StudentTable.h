#include <iostream>
#include "Student.h"
#pragma once

class StudentTable
{
	public:
		bool TryAdd(Student newStudent);
		bool TryDelete(unsigned id);

		bool TryPrint();

	private:
		static const unsigned capacity = 100;
		unsigned size = 0;
		Student studentArray[capacity];

		void Print();

		void InsertingAtTheBeginning(Student newStudent);
		void DeleteStudent(unsigned index);
		short FindStudent(unsigned id);
};

