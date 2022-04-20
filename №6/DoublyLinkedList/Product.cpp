#include "Product.h"

Product::Product(unsigned productCode, unsigned price, Time saleDate, Time returnDate)
{
	this->productCode = productCode;
	this->price = price;
	this->saleDate = saleDate;
	this->returnDate = returnDate;
	if (this->returnDate.year != 0)
		returned = true;
}

void Product::PrintInfo()
{
	printf("ID: %03i\n", productCode);
	printf("Sale date: %02i.%02i.%i\n", saleDate.day, saleDate.month, saleDate.year);
	printf("Price: %i Rub\n", price);
	if (returned)
		printf("Return date: %02i.%02i.%i\n", returnDate.day, returnDate.month, returnDate.year);
}

bool Product::operator==(const Product& other)
{
	bool isSame = (this->productCode == other.productCode) && (this->returned == other.returned) && (this->price == other.price);
	if (isSame)
	{
		isSame = (this->saleDate == other.saleDate) && (this->returnDate == other.returnDate);
	}

	return isSame;
}
void Product::operator=(const Product& other)
{
	this->productCode = other.productCode;
	this->price = other.price;
	this->returned = other.returned;
	this->saleDate = other.saleDate;
	this->returnDate = other.returnDate;
}


