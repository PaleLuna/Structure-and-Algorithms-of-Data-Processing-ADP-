#include <iostream>
#include <string>
#include <map>
#include "ListStack.h"

using namespace std;

map<char, unsigned short> prec;

string infixToPostfix(string infix);

int main()
{
	setlocale(LC_ALL, "ru");
	prec.emplace('/', 3);
	prec.emplace('*', 3);
	prec.emplace('+', 2);
	prec.emplace('-', 2);
	prec.emplace('(', 1);

	string input;
	while (true)
	{
		printf("Введите выражение: ");
		getline(cin, input);
		if (input[0] == '0')
			break;
		printf("%s -> %s\n\n", input.c_str(), infixToPostfix(input).c_str());
	}
	return 0;
}

string infixToPostfix(string infix)
{
	ListStack<char> opStack;
	string postfix;

	for (int i = 0; i < infix.size(); i++)
	{
		if (((47 < infix[i]) and (infix[i] < 58)) or ((64 < (int)infix[i]) and (infix[i] < 91)))
			postfix += infix[i];

		else if (infix[i] == '(')
			opStack.Push(infix[i]);

		else if (infix[i] == ')')
		{
			char topChar = opStack.Pop();
			while (topChar != '(')
			{
				postfix += topChar;
				topChar = opStack.Pop();
			}
		}
		else if (infix[i] != 32)
		{
			char currentChar;
			opStack.GetHead(currentChar);
			while (!opStack.IsEmpty() and (prec[currentChar] >= prec[infix[i]]))
				postfix += opStack.Pop();

			opStack.Push(infix[i]);
		}
	}

	while (!opStack.IsEmpty())
		postfix += opStack.Pop();

	return postfix;
}