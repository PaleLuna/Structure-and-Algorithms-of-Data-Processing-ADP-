#include "Time.h"

Time::Time(unsigned day, unsigned month, unsigned year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Time::operator=(const Time& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

bool Time::operator==(const Time& other)
{
	bool isSame = this->year == other.year;
	if (isSame)
		isSame = this->month == other.month;
	if (isSame)
		isSame = this->day == other.day;

	return isSame;
}
