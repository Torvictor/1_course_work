#include <iostream>
#include "proto.h"

using namespace std;

/ * ------------------------------------------------ -------------------------------------------------- ----- *
Assignment: implementation of the algorithm of the sorting station (reverse Polish recording).
| ------------------------------------------------- -------------------------------------------------- ------
Assignment main_11.h: demonstration of the program (testing algorithm of the station).
| ------------------------------------------------- -------------------------------------------------- ------
| Contents fpolish_note.cpp:
| `a function for pushing an item onto the stack;
| `a function for pushing an item out of the stack;
| `function to generate a reverse Polish record;
| `function to identify the priority of a given arithmetic operation.
| ------------------------------------------------- -------------------------------------------------- ------
Proto.h: prototyping functions.
* ------------------------------------------------- -------------------------------------------------- ---- * /
int main_11()
{
	setlocale(LC_ALL, "Russian");

	StackASY *begin = NULL;

	char* InStr = new char[250];
	
	int outstr_len = 0;
	char* OutStr = new char[outstr_len];

	int action_ch;
	bool go_infix = false;//сигнал о том, введена ли инфиксная запись
	bool go_polish = false;//сигнла о том, что запись переведена

	do
	{
		system ("cls");
		cout << "Choose the actions: \ n";
		cout << "0 - Exit to the main menu \ n";
		cout << "1 - Enter the infix entry \ n";
		cout << "2 - Translate the entered infix entry into the reverse Polish \ n";
		cout << "3 - Display infix and reverse Polish records \ n";
		cout << ">";

		cin >> action_ch;
		system("cls");

		switch (action_ch)
		{
		case 1:
		{
			go_infix = true;

			cout << "Enter the infix record (characters and operators are allowed: '+', '-', '/', '*'): \ n";
			cin >> InStr;

			go_polish = false;
			cout << endl;
			system("pause");
			break;
		}
		case 2:
		{
			if (go_infix == false)
			{
				cout << "Insufficient data ... Probably you forgot to enter something!" << endl;
				system("pause");
				break;
			}

			go_polish = true;
			ResPolishNote(InStr, OutStr, outstr_len, begin);
			cout << "Data processed successfully!";

			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			if (go_polish == false)
			{
				cout << "Insufficient data ... Probably you forgot to enter something!" << endl;
				system("pause");
				break;
			}

			cout << "The initial infix entry:" << InStr << endl;
			cout << "Reverse Polish entry:" << OutStr << endl;

			cout << endl;
			system("pause");
			break;
		}
		}
	} while (action_ch != 0);

	cout << endl;
	system("pause");
	return 0;
}