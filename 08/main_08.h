#include <iostream>
#include "RK_file.h"

using namespace std;

/ * ------------------------------------------------ -------------------------------------------------- ----- *
| ------------------------------------------------- -------------------------------------------------- ------
Assignment: the implementation of the algorithm for finding a substring in a string by the Rabin-Karp method.
| ------------------------------------------------- -------------------------------------------------- ------
Purpose main_08.h: demonstration of the program (testing the search algorithm Rabin-Karp).
| ------------------------------------------------- -------------------------------------------------- ------
| Assignment RK_file.cpp: creating the necessary functions for the search for the "Rabin-Karp Algorithm":
| `function for outputting an integer array to the screen;
| `hash function;
| `recalculation of the hash function;
| `for a given position, the function pulls the required substring from the text;
| `search for Rabin-Karp;
| `a function to output occurrences of a template in the text; | | | |
| ------------------------------------------------- -------------------------------------------------- ------
| Assignment RK_file.h: creating prototypes of functions.
* ------------------------------------------------- -------------------------------------------------- ---- * /

int main_08()
{
	setlocale(LC_ALL, "Russian");

	char* text = new char[250];
	int text_len;

	char* templ = new char[250];
	int templ_len;

	int action_ch;
	bool go_text = false;
	bool go_templ = false;/

	do
	{
		system("cls");
		cout << "Select actions:\n";
		cout << " 0 - Exit to the main menu\n";
		cout << " 1 - Enter the original string\n";
		cout << " 2 - Enter the search string (substring)\n";
		cout << " 3 - Finding and outputting occurrences of occurrences of a substring in a string\n";
		cout << ">";

		cin >> action_ch;
		system("cls");

		switch (action_ch)
		{
		case 1:
		{
			go_text = true;

			cout << "enter the original string: ";
			cin >> text;

			text_len = strlen(text);
			cout << "length of input string: " << text_len << endl;
			cout << endl;

			cout << endl;
			system("pause");
			break;
		}
		case 2:
		{
			go_templ = true;
			cout << "Enter the substring you want to find: ";
			cin >> templ;

			templ_len = strlen(templ);
			cout << "length of input string: " << templ_len << endl;
			cout << endl;

			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			if (go_templ == false)
			{
				cout << "Insufficient data ... You probably forgot something to enter!" << endl;
				system("pause");
				break;
			}

			//array of codes "ASCII" for symbols from teamplates:
			int* Code_templ = new int[templ_len];

			//hash-value:
			unsigned long int hash_templ = HashFunc(templ, templ_len, Code_templ);

			cout << "The hash value for the template: " << hash_templ;
			cout << endl << endl;

			cout << "Output ASCII codes of all characters from the template:";
			PrintArrayRK(Code_templ, templ_len);
			cout << endl;

			int size = 0;

			int* Result = new int[text_len];

			int result = RabinKarp_Search(text, text_len, templ, templ_len, hash_templ, Result, size);
			size = result;

			cout << "Original string:" << text << endl; // for clarity
			cout << "The search string:" << templ << endl;;
			PrintResultRK(Result, size);

			system("pause");
			break;
		}
		}
	} while (action_ch != 0);

	cout << endl;
	system("pause");
	return 0;
}