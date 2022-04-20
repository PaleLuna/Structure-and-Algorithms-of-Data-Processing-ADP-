#pragma once
struct Time
{
	unsigned day;
	unsigned month;
	unsigned year;
	
	Time(unsigned day = 0, unsigned month = 0, unsigned year = 0);
	void operator=(const Time& other);
	bool operator==(const Time& other);
};

