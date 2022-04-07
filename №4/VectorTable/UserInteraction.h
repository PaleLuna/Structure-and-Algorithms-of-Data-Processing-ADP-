#include "StudentTable.h"
#include "Input.h"
#pragma once

class UserInteraction
{
public:
	bool Actions(unsigned choice);

private:
	StudentTable table;

	Student& CreatingStudent();
	void StudentInitialization();
	void DeleteStudent();
};
