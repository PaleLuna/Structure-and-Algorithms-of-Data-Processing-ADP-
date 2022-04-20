#include <iostream>
#include "Time.h"
#pragma once

struct Product
{
	unsigned productCode;
	unsigned price;
	bool returned = false;

	Time saleDate;
	Time returnDate;

	Product(unsigned productCode = 0, unsigned price = 0, Time saleDate = Time(), Time returnDate = Time());
	void PrintInfo();
	void operator=(const Product& other);
	bool operator==(const Product& other);
};

