#include <iostream>
#include <ctime>
#include "ball-massive.h"

using namespace std;

/*-------------------------------------------------------------------------------------------------------*
|Tusk: realization of the sorting by bubble method.
|---------------------------------------------------------------------------------------------------------
|Appointment of the main_01.h: show sorting.
|---------------------------------------------------------------------------------------------------------
|Appointment of the ball-massive.cpp: Create the necessary functions for realization the sorting for bubble method.
|---------------------------------------------------------------------------------------------------------
|Appointment of the ball-massive.h: create prototypes.
*-------------------------------------------------------------------------------------------------------*/
int main_01()
{
	srand(time(NULL));

	int quant;//size of array
	int *mas = NULL;//empty array

	int action_ch;//choice of actions by the user

	bool go_arr = false;
	bool go_sort = false;

	do
	{
		system("cls");
		cout << "Select actions:\n";
		cout << " 0 - Exit to the main menu\n";
		cout << " 1 - Generate an array by random numbers\n";
		cout << " 2 - Generate an array by entering numbers\n";
		cout << " 3 - Sort the generated array\n";
		cout << " 4 - Output of the sorted array to the screen\n";
		cout << ">";

		cin >> action_ch;
		system("cls");

		switch (action_ch)
		{
		case 1://Generate an array by random number:
		{
			go_arr = true;
			cout << "Enter the size of array: ";
			cin >> quant;

			mas = new int[quant];

			for (int i = 0; i < quant; i++)
			{
				mas[i] = rand() % 100;
			}
			cout << "Generated array: ";
			PrintMas(quant, mas);

			go_sort = false;
			cout << endl;
			system("pause");
			break;
		}
		case 2://Generate an array by entering user:
		{
			go_arr = true;

			cout << "Enter the size of array: ";
			cin >> quant;

			mas = new int[quant];
			for (int i = 0; i < quant; i++)
			{
				cout << "Enter the element to add to array: ";
				cin >> mas[i];
				cout << endl;
			}

			cout << "Generated array: ";
			PrintMas(quant, mas);

			go_sort = false;
			cout << endl;//newline
			system("pause");
			break;
		}
		case 3://Array sorting:
		{
			if (go_arr == false)
			{
				cout << "Insufficient data... probably you forgot something to enter!" << endl;
				system("pause");
				break;
			}

			go_sort = true;

			SortMas(quant, mas);
			cout << "Numbers are sorted!" << endl;

			system("pause");
			break;
		}
		case 4://Output the sorted array to the screen:
		{
			if (go_sort == false)
			{
				cout << "Insufficient data... probably you forgot something to enter!" << endl;
				system("pause");
				break;
			}

			cout << "Output of the sorted array (in the opposite): ";
			PrintMas(quant, mas);

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