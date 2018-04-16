#include <iostream>
#include "AVL_templfunc.h"

using namespace std;

template <class T>
//функция для выбора действий с деревом:
void ActionsWithAVLTree(Tree<T> *root)
{
	bool high = false;//высота не подверглась изменению
	int action_ch;

	do
	{
		system ("cls");
		cout << "Choose the actions: \ n";
		cout << "0 - Quit the AVL tree \ n";
		cout << "1 - Add element / s to the tree \ n";
		cout << "2 - Remove an element from the tree \ n";
		cout << "3 - Output the tree to the screen \ n";
		cout << ">";

		cin >> action_ch;
		system("cls");

		switch (action_ch)
		{
		case 1:
		{
			int count;//кол-во элементов в дереве
			cout << "Enter the number of elements to add to the tree:";
			cin >> count;
			cout << endl;

			T add_el;//добавляемый элемент типа T

			//поэлементно вводим элементы в дерево:
			for (int i = 0; i < count; i++)
			{
				cout << "Enter the element to add to the AVL tree:";
				cin >> add_el;
				SearchAndInsert(add_el, &root, high);//вставка заданного эл. в нужное место
			}
			system("pause");
			break;
		}
		case 2:
		{
			T del_el;//удаляемый элемент типа T
			cout << "Enter the element you want to delete:";
			cin >> del_el;
			Delete(del_el, &root, high);//удаление заданного элемента
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Вывод скомбинированного AVL-дерева: " << endl;
			PrintTree(root, 0);//обход полученного дерева
			system("pause");
			break;
		}
		}
	} while (action_ch != 0);
}

/ * ------------------------------------------------ -------------------------------------------------- ----- *
Task: implementation of building a balanced tree (AVL-tree).
| | ------------------------------------------------- - ------------------------------------------------- - -----
The purpose of main_10.h: demonstration of the program (testing the AVL-tree).
| | ------------------------------------------------- - ------------------------------------------------- - -----
| | Assignment AVL_templfunc.h: create the necessary functions for building an AVL-tree:
| | `search function to insert this element into the desired place in the tree;
| | `function for balancing the left side of the tree;
| | `function for balancing the right side of the tree;
| | `helper function to delete a node;
| | `function to delete a node;
| | `function for outputting a tree (bypassing it). | | | | | | | |
| | ------------------------------------------------- - ------------------------------------------------- - -----
Note: in main_10.h there is a function for calling all necessary program functions with the selected
| | type of user data (built on templates).
* ------------------------------------------------- -------------------------------------------------- ---- * /
int main_10()
{
	setlocale(LC_ALL, "Russian");

	int tchoice;//выбор типа данных пользователем
	cout << "Select the data type for the tree elements: \ n";
	cout << "1 - int; 2 - float; 3 - double; 4 - char: ";
	cin >> tchoice;

	//По выбору пользователя определяем используемый тип данных:
	switch (tchoice)
	{
	case 1://для типа int:
	{
		//начало (как и все элементы дерева) будут типа int:
		Tree<int>* root = (Tree<int>*)NULL;

		//вызываем функции с типом элементов int:
		ActionsWithAVLTree(root);
		break;
	}
	case 2://для типа float:
	{
		//начало (как и все элементы дерева) будут типа float:
		Tree<float>* root = (Tree<float>*)NULL;

		//вызываем функции с типом элементов float:
		ActionsWithAVLTree(root);
		break;
	}
	case 3://для типа double:
	{
		//начало (как и все элементы дерева) будут типа double:
		Tree<double>* root = (Tree<double>*)NULL;

		//вызываем функции с типом элементов double:
		ActionsWithAVLTree(root);
		break;
	}
	case 4://для типа char:
	{
		//начало (как и все элементы дерева) будут типа char:
		Tree<char>* root = (Tree<char>*)NULL;

		//вызываем функции с типом элементов char:
		ActionsWithAVLTree(root);
		break;
	}
	default://иначе введенный тип неверный!
	{
		cout << "Invalid type ... \ n";
		break;
	}
	}

	cout << endl;
	system("pause");
	return 0;
}