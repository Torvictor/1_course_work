#include <iostream>

using namespace std;

template<class T>
struct Stack
{
	T elstack;
	Stack *next;
};

template<class T>
void CreateStack(Stack<T> **b)
{
	int n;
	cout << "Enter the number of stack elements:";
	cin >> n;

	if (n == 0)
	{
		cout << "There are no entries!" << endl;
		return;
	}

	Stack<T>* first = new Stack<T>;
	*b = first;
	cout << "Enter the first element of the stack:";
	cin >> first->elstack;
	first->next = NULL;

	for (int i = 1; i < n; i++)
	{
		Stack<T>* cur = new Stack<T>;
		cout << "Enter the following stack element:";
		cin >> cur->elstack;
		first->next = cur;
		cur->next = NULL;
		first = cur;
	}
}

template<class T>
void PrintStack(Stack<T> *b)
{
	Stack<T>* print;

	print = b;

	cout << "The received elements of the stack:";
	while (print != NULL)
	{
		cout << print->elstack << " -> ";
		print = print->next;
	}
	cout << "NULL\n";
}

template<class T>
void PushToStack(Stack<T> **begin, const T &add_el)
{
	Stack<T>* helper = new Stack<T>;

	cout << "Adding an element" << add_el << "to the stack:" << endl;
	helper->elstack = add_el;
	helper->next = *begin;
	*begin = helper;
}

template<class T>
void PopFromStack(Stack<T> **b)
{
	//если список пуст:
	if (*b == NULL)
	{
		return;
	}
	Stack<T> *del_el = *b;

	*b = del_el->next;

	cout << "Deleting an item from the stack:";
	delete del_el;
	cout << endl;
}