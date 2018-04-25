#include <iostream>
#include <ctime>
#include "f_kmp.h"
#include <cstring>

using namespace std;

/*-------------------------------------------------------------------------------------------------------*
|Tusk: realization of thesearching by KMP method.
|---------------------------------------------------------------------------------------------------------
|Appointment of the main_01.h: show searching.
|---------------------------------------------------------------------------------------------------------
|Appointment of the f_kmp.cpp: Create the necessary functions for realization the searching of KMP method.
|---------------------------------------------------------------------------------------------------------
|Appointment of the f_kmp.h: create prototypes.
*-------------------------------------------------------------------------------------------------------*/
int main_06()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	char* text = new char[250];
	int text_len;

	char* str = new char[250];
	int str_len;

	int action_ch;
	bool go_text = false;
	bool go_templ = false;

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
			cin >> str;

			str_len = strlen(str);
			cout << "length of input string: " << str_len << endl;
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

			int common_len = str_len + text_len + 1;
			char* common = new char[common_len + 1];

			Combination(str, text, common, common_len);

			cout << "Demonstration of the searched and initial lines separated by the symbol '|':" << endl;
			cout << common << endl;
			cout << endl;

			int *PrefixArr = new int[common_len];

			PrefixFunction(common, PrefixArr, common_len);

			cout << "Prefix function for the common string: " << endl;

			PrintArrayKMP(PrefixArr, common_len);
			cout << endl;

			KMP_Search(str, str_len, common_len, PrefixArr);

			system("pause");
			break;
		}
		}
	} while (action_ch != 0);

	cout << endl;
	system("pause");
	return 0;
}
