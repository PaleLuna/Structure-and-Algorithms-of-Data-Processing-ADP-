#include <iostream>
#include <fstream>
#include <conio.h>
#include "StoreManager.h"
using namespace std;

StoreManager storeManager;
bool ISRUN = true;

void PrintMenu();
void CreateNewList();
Product& CreateProduct();
void SetTime(Time& time);

void SelectionProcessing(unsigned selection)
{
	Time timeToDelete;
	switch (selection)
	{
		case 0:
			printf("Выходим...\n");
			ISRUN = false;
			break;
		case 1:
			CreateNewList();
			break;
		case 2:
			storeManager.AddProduct(CreateProduct());
			break;
		case 3:
			storeManager.RefreshSort();
			break;
		case 4:
			printf("Введите дату: ");
			SetTime(timeToDelete);
			storeManager.DeleteAtDate(timeToDelete);
			break;
		case 5:
			storeManager.PrintProducts();
			break;
		case 6:
			system("cls");
			PrintMenu();
			break;
		default:
			printf("Действие не определено.\n");
			break;
		}
}

int main()
{
	setlocale(LC_ALL, "ru");
	PrintMenu();

	unsigned selection;
	do
	{
		printf("Действие №");
		cin >> selection;
		SelectionProcessing(selection);
	} while (ISRUN);

	return 0;
}

void PrintMenu()
{
	ifstream file("MenuText.txt");

	if (file.is_open())
	{
		char text[1024];
		file.getline(text, 1024, '\0');
		printf("%s", text);
	}
}

void CreateNewList()
{
	List<Product> newLst;

	do
	{
		newLst.Push_back(CreateProduct());
	} while (_getch() != 27);

	storeManager.UpdateList(newLst);
}
Product& CreateProduct()
{
	Product newProduct;
	printf("Введите код продукта: ");
	cin >> newProduct.productCode;
	printf("Введите цену на продукт: ");
	cin >> newProduct.price;
	printf("Укажите, был ли возвращен товар: ");
	cin >> newProduct.returned;

	printf("Введите дату продажи: ");
	SetTime(newProduct.saleDate);
	if (newProduct.returned)
	{
		printf("Введите дату возврата: ");
		SetTime(newProduct.returnDate);
	}
	cout << endl;

	return newProduct;
}
void SetTime(Time& time)
{
	scanf_s("%d%*c%d%*c%d", &time.day, &time.month, &time.year);
}