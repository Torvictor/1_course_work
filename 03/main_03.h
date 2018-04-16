#include <iostream>
#include <ctime>
#include "fquick.h"

using namespace std;

/*-------------------------------------------------------------------------------------------------------*
|Tusk: realization of the sorting by quick method.
|---------------------------------------------------------------------------------------------------------
|Appointment of the main_03.h: show sorting.
|---------------------------------------------------------------------------------------------------------
|Appointment of the fquick.cpp: Create the necessary functions for realization the sorting for quick method.
|---------------------------------------------------------------------------------------------------------
|Appointment of the ball-massive.h: create prototypes.
*-------------------------------------------------------------------------------------------------------*/
int main_03()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int quant;
	int *Arr = NULL;
	int action_ch;
	bool go_arr = false;//сигнал о том, что сгенерирован массив
	bool go_sort = false;//сигнал о том, что выполнена сортировка

	do
	{
		ystem("cls");
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

			cout << "Enter the size of array:  ";
			cin >> quant;

			Arr = new int[quant];

			RandomValuesQuick(quant, Arr);

			ccout << "Generated array: ";
			PrintArrayQuick(quant, Arr);

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

			Arr = new int[quant];

			for (int i = 0; i < quant; i++)
			{
				cout << "Enter the element to add to array: ";
				cin >> Arr[i];
				cout << endl;
			}

			cout << "Generated array:";
			PrintArrayQuick(quant, Arr);

			go_sort = false;
			cout << endl;
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

			QuickSort(0, quant - 1, Arr);
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

			cout << "Output of the sorted array: ";
			PrintArrayQuick(quant, Arr);

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