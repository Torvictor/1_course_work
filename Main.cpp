#include <iostream>
#include "01 \ main_01.h" // connect a directory of files containing a sorted bubble
#include "02 \ main_02.h" // connect the directory of files containing the Shell sorting
#include "03 \ main_03.h" // connect a directory of files containing fast sorting
#include "04 \ main_04.h" // connect the file directory containing the pyramid sorting
#include "05 \ main_05.h" // connect the file directory containing bit-by-bit sorting
#include "06 \ main_06.h" // connect the file directory containing the CMS search
#include "07 \ main_07.h" // connect a directory of files containing a BM search
#include "08 \ main_08.h" // connect the directory of files containing the RC-search
#include "09 \ main_09.h" // connect the directory of files containing stacks and queues
#include "10 \ main_10.h" // connect the file directory containing the AVL-tree
#include "11 \ main_11.h" // connect the directory of files containing al. variety. stations

using namespace std;

/* ------------------------------------------------ -------------------------------------------------- ------ *
Coursework.
| ------------------------------------------------- -------------------------------------------------- -------
| Sergeev Victor.
| ------------------------------------------------- -------------------------------------------------- -------
| Assignment:
| `combine all LR for 1 course, 2 sem;
| `implement a convenient user menu for calls to all the necessary LRs by the user;
| `make a submenu for each LR (with the choice of the necessary actions).
| ------------------------------------------------- -------------------------------------------------- -------
Main call functions content:
| `Main - call the desired LR user.
| `main_01 - demonstration of sorting by a bubble;
| `main_02 - demonstration of sorting of Shell;
| `main_03 - demonstration of sorting Hoare;
| `main_04 - demonstration of heap sorting;
| `main_05 - demonstration of sorting by rank;
| `main_06 - demonstration of CMS-search;
| `main_07 - demonstration of BM-search;
| `main_08 - demonstration of RC-search;
| `main_09 - demonstration of stacks and queues;
| `main_10 - demonstration of the AVL-tree;
| `main_11 - demonstration of the algorithm sorting art.
| ------------------------------------------------- -------------------------------------------------- -------
Note: before each function main_N there is a short description of the Nth LR!
* ------------------------------------------------- -------------------------------------------------- ----- */
int main()
{/ * Main function * /

	setlocale(LC_ALL, "Russian");

	int choice;// to select a topic by the user

	do
	{
		system ("cls"); // cleaning the console
		cout << "Choose a theme: \ n";
		cout << "0 - Exit \ n";
		cout << "1 - Sorting by a bubble \ n";
		cout << "2 - Sorting Shell \ n";
		cout << "3 - Sorting Hoare (fast) \ n";
		cout << "4 - Sorting Heap \ n";
		cout << "5 - Sorting by rank (bitwise) \ n";
		cout << "6 - Search for Knut-Morris-Pratt \ n";
		cout << "7 - Boyer-Moore Search \ n";
		cout << "8 - Search for Rabin-Karp \ n";
		cout << "9 - Stacks and queues \ n";
		cout << "10 - Balanced binary tree (AVL) \ n";
		cout << "11 - Algorithm of the sorting station (reverse Polish entry) \ n";
		cout << ">";

		cin >> choice; // enter the number of the desired topic

		system("cls");
		
		switch (choice) // select the desired topic:
		{
			case 1: main_01(); break;
			case 2: main_02(); break;
			case 3: main_03(); break;
			case 4: main_04(); break;
			case 5: main_05(); break;
			case 6: main_06(); break;
			case 7: main_07(); break;
			case 8: main_08(); break;
			case 9: main_09(); break;
			case 10: main_10(); break;
			case 11: main_11(); break;
		}
	} while (choice! = 0); // not yet 0, the program does not finish its work

	return 0;
}
