#include <iostream>
#include <ctime>

using namespace std;

const int amountEl = 50;
const int multiple = 7;

void FillingArr(int* array);
void ShowArr(int* array, int amountEl);
int SumOfDigits(int num);
void FindingMultiples(int* baseArr, int* fillableArray);


int main()
{
	system("chcp 1251>nul");

	int baseArray[amountEl];
	int newArray[amountEl];

	FillingArr(baseArray);
	printf("Отображение массива:\n");
	ShowArr(baseArray, amountEl);

	FindingMultiples(baseArray, newArray);

	printf("Числа, сумма цифр которых кратна %i:\n", multiple);
	ShowArr(newArray, 10);



	system("pause>nul");
	return 0;
}

void FillingArr(int* array)
{
	srand(time(NULL));
	for(int i = 0; i < amountEl; i++) array[i] = (rand() % 1000) + 1;
}

void ShowArr(int* array, int amountEl)
{
	printf("[\n");
	for(int i = 0; i < amountEl-1; i++)
	{
		printf("%5i,", array[i]);
		if((i+1) % 10 == 0)
		{
			printf("\n");
		}
	}
	printf("%5i\n]\n\n", array[amountEl-1]);
}

int SumOfDigits(int num)
{
	int sum = 0;
	int counter = 0;
	int digit;

	do
	{
		digit = num % 10;
		sum += digit;

		num = num / 10;
		counter++;

	} while (num > 0);

	return sum;
}

void FindingMultiples(int* baseArr, int* fillableArray)
{
	int counter = 0;

	for (int i = 0; i < amountEl; i++)
	{
		int sum = SumOfDigits(baseArr[i]);

		if (sum % multiple == 0)
		{
			fillableArray[counter] = baseArr[i];
			if (counter > 0)
			{
				for (int i = 1; i <= counter; i++)
				{
					for (int j = 0; j <= counter; j++)
					{
						if (fillableArray[i] > fillableArray[j])
						{
							swap(fillableArray[i], fillableArray[j]);
						}
					}		
				}
			}
			counter++;
		}
	}
}


