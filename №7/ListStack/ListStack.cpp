#include <iostream>
#include <string>
#include <map>
#include "ListStack.h"

using namespace std;

map<char, unsigned short> prec ={	{'/', 3},
									{'*', 3},
									{'+', 2},
									{'-', 2},
									{'(', 1}
								};

string infixToPostfix(string infix);

int main()
{
	setlocale(LC_ALL, "ru");

	printf("%s", infixToPostfix("( A + B ) * ( C + D )").c_str());

	return 0;
}

string infixToPostfix(string infix)
{
	ListStack<char> opStack;
	string postfix;

	for (int i = 0; i < infix.size(); i++)
	{
		if ((47 < infix[i] < 58) or (64 < infix[i] < 91))
			postfix += infix[i] + ' ';
		else if (infix[i] == '(')
			opStack.Push(infix[i]);
		else if (infix[i] == ')')
		{
			char topChar;
			opStack.Pop(topChar);
			while (topChar != '(')
			{
				postfix += topChar;
				opStack.Pop(topChar);
			}
		}
		else
		{
			char currentChar;
			opStack.GetHead(currentChar);
			while (!opStack.IsEmpty() and (prec.at(currentChar) >= prec.at(infix[i])))
			{
				opStack.Pop(currentChar);
				postfix += currentChar + ' ';
			}

			opStack.Push(infix[i]);
		}
	}

	while (!opStack.IsEmpty())
	{
		char currentChar;
		opStack.Pop(currentChar);

		postfix += currentChar + ' ';
	}

	return postfix;
}