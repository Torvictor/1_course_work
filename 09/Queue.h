#include <iostream>

using namespace std;

template<class T>
struct Queue
{
	T qu;
	Queue *next;à
	Queue *prev;
};

template<class T>
void CreateQueue(Queue<T> **b)
{
	int n;
	cout << "Enter the number of queue elements:";
	cin >> n;

	if (n == 0)
	{
		cout << "There are no entries!" << endl;
		return;
	}

	Queue<T>* first = new Queue<T>;
	*b = first;

	cout << "Enter the first element of the queue:";
	cin >> first->qu;

	first->prev = NULL;
	first->next = NULL;

	for (int i = 1; i < n; i++)
	{
		Queue<T>* cur = new Queue<T>;
		cout << "Enter the next element of the queue:";
		cin >> cur->qu;
		first->next = cur;
		cur->prev = first;
		cur->next = NULL;
		first = cur;
	}
}

template<class T>
void PrintQueue(Queue<T> *b)
{
	if (b == NULL)
	{
		cout << "The queue is empty!";
		return;
	}

	Queue<T> *cur = b;

	cout << "Received queue elements:";
	cout << "NULL <-> ";
	while (cur != NULL)
	{
		cout << cur->qu << " <-> ";
		cur = cur->next;
	}
	cout << "NULL\n";
}

template<class T>
void PushToQueue(Queue<T> **b, const T &add_el)
{
	cout << "Adding an element" << add_el << "to the queue:" << endl;

	if (*b == NULL)
	{
		Queue<T> *first = new Queue<T>;

		*b = first;

		first->qu = add_el;
		first->prev = NULL;
		first->next = NULL;
		return;
	}
	Queue<T>* cur = new Queue<T>;
	cur = *b;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	Queue<T> *end = new Queue<T>;

	end->qu = add_el;
	end->next = NULL;
	end->prev = cur;
	cur->next = end;
}

template<class T>
void PopFromQueue(Queue<T> **b)
{
	if (*b == NULL)
	{
		cout << "No items to delete!" << endl;
		return;
	}

	Queue<T> *del_el = *b;
	cout << "Deleting an item from the queue:";

	if ((*b)->next != NULL)
	{
		*b = del_el->next;
		(*b)->prev = NULL;
	}
	else
	{
		*b = del_el;
		*b = NULL;
	}

	delete del_el;
	cout << endl;
}
