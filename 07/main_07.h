#include <iostream>
#include "BM_header.h"

using namespace std;

//realization of the searching Boyer-Moore:
int main_07()
{
	setlocale(LC_ALL, "Russian");

	char* text = new char[250];
	int text_len;
	char* templ = new char[250];
	int templ_len;

	int action_ch;
	bool go_text = false;
	bool go_templ = false;

	do
	{
		system("cls");
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


			int* Result = new int[text_len];

			int size = BMsearch(text, templ, text_len, templ_len, Result);

			cout << "Source string : " << text << endl;
			cout << "Search string: " << templ << endl;

			PrintArrBM(Result, size);

			system("pause");
			break;
		}
		}
	} while (action_ch != 0);

	cout << endl;
	system("pause");
	return 0;
}
