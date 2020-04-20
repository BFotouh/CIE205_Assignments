#include <iostream>
#include <iomanip>
#include "string"
#include "Classes/ArrayStack.h"

using namespace std;

string toPostFix(string exp);
string toInFix(string exp);
bool IsOperand(char C);
int IsOperatorwithPrec(char C);

int main(void)
{
	// prompt the user for mode (infix or postfix)
	int mode = 0;
	do
	{
		cout << "Enter the number of the mode you wish to use: " << endl;
		cout << "[1]: to convert form infix to postfix." << endl;
		cout << "[2]: to convert form infix to postfix." << endl;
		cin >> mode;
	} while (mode < 1 || mode > 2);
	
	// prompt the user for input
	cout << "Enter the expression you wish to convert: " << endl;
	string input, Output;
	cin >> input;

	// get the expression
	if (mode == 1)
	{
		Output = toPostFix(input);
		cout << "The PostFix expression: ";
		cout << setw(6) << Output << "\n";
	}
	else if (mode == 2)
	{
		Output = toInFix(input);
		cout << "The InFix expression: ";
		cout << setw(6) << Output << "\n";
	}
}

string toPostFix(string exp)
{
	ArrayStack<char> S;

	string postfixExpress;
	int size = exp.length();

	for (int i = 0; i < size; i++)
	{
		if (IsOperand(exp[i]))
		{
			postfixExpress += exp[i];
		}
		else if (exp[i] == '(')
		{
			S.push('(');
		}
		else if (exp[i] == ')')
		{
			char c;
			S.peek(c);
			while ((!S.isEmpty()) && (c != '('))
			{
				S.pop(c);
				postfixExpress += c;
				S.peek(c);
			}
			if (c == '(')
			{
				S.pop(c);
			}
		}
		else
		{
			char c;
			S.peek(c);
			while (!S.isEmpty() && IsOperatorwithPrec(exp[i]) <= IsOperatorwithPrec(c))
			{
				S.pop(c);
				postfixExpress += c;
				S.peek(c);
			}
			S.push(exp[i]);
		}
	}

	while (!S.isEmpty())
	{
		char c;
		S.pop(c);
		postfixExpress += c;
	}
	return postfixExpress;
}

string toInFix(string exp)
{
	ArrayStack<string> S;
	string infixExpress;
	int size = exp.length();
	for (int i = 0; i < size; i++)
	{
		if (IsOperand(exp[i]))
		{
			string s(1, exp[i]);
			S.push(s);
		}
		else
		{
			string s1, s2;
			S.pop(s1);
			S.pop(s2);
			S.push("(" + s2 + exp[i] + s1 + ")");
		}
	}
	while (!S.isEmpty())
	{
		string c;
		S.pop(c);
		infixExpress += c;
	}
	return infixExpress;
}

bool IsOperand(char C)
{
	if (C >= 'A' && C <= 'Z') 
	{ 
		return true; 
	}
	if (C >= 'a' && C <= 'z') 
	{ 
		return true; 
	}
	if (C >= '0' && C <= '9') 
	{ 
		return true; 
	}
	return false;
}

int IsOperatorwithPrec(char C)
{
	if (C == '^')
		return 3;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '+' || C == '-')
		return 1;
	else
		return -1;
}