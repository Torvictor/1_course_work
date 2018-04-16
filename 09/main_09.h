#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

template <class T>
// function for selecting actions with the stack:
void ActionsWithStack(Stack<T>* s_begin)
{
	int action_ch;

	do
	{
		system ("cls");
		cout << "Choose the actions: \ n";
		cout << "0 - Finish working with stacks \ n";
		cout << "1 - Create a stack \ n";
		cout << "2 - Add an item to the stack \ n";
		cout << "3 - Remove an item from the stack \ n";
		cout << "4 - Show the stack on the screen \ n";
		cout << ">";

		cin >> action_ch;
		system("cls");

		switch (action_ch)
		{
		case 1:
		{
			CreateStack (& s_begin); // pass the address of the pointer to the beginning
			// address - where this pointer is stored
			system("pause");
			break;
		}
		case 2:
		{
			T add_el;
			cout << "Enter the item to add to the stack:";
			cin >> add_el;
			cout << endl;

			PushToStack(&s_begin, add_el);
			system("pause");
			break;
		}
		case 3:
		{
			PopFromStack(&s_begin);
			system("pause");
			break;
		}
		case 4:
		{
			PrintStack(s_begin);
			cout << endl;
			system("pause");
			break;
		}
		}
	} while (action_ch != 0);
}

void DemonstrationOfStack()
{
	cout << "Demonstration of the stack: " << endl << endl;

	int choice_st;
	cout << "Choose the data type for the stack elements: \ n";
	cout << "1 - int; 2 - float; 3 - double; 4 - char: ";
	cin >> choice_st;

	switch (choice_st)
	{
	case 1:
	{
		Stack<int>* s_begin = (Stack<int>*)NULL;

		ActionsWithStack(s_begin);
		break;
	}
	case 2:
	{
		Stack<float>* s_begin = (Stack<float>*)NULL;
		ActionsWithStack(s_begin);
		break;
	}
	case 3:
	{
		Stack<double>* s_begin = (Stack<double>*)NULL;
		ActionsWithStack(s_begin);
		break;
	}
	case 4:
	{
		Stack<char>* s_begin = (Stack<char>*)NULL;
		ActionsWithStack(s_begin);
		break;
	}
	default:
	{
		cout << "Invalid type ... \ n";
		break;
	}
	}
}

template <class T>
void ActionsWithQueue(Queue<T>* q_begin)
{
	int action_ch;

	do
	{
		system ("cls");
		cout << "Choose the actions: \ n";
		cout << "0 - Quit the queues \ n";
		cout << "1 - Create a queue \ n";
		cout << "2 - Add item to the queue \ n";
		cout << "3 - Remove item from the queue \ n";
		cout << "4 - Displaying the queue on the screen \ n";

		cin >> action_ch;
		system("cls");

		switch (action_ch)
		{
		case 1:
		{
			CreateQueue(&q_begin);
			system("pause");
			break;
		}
		case 2:
		{
			T addel;
			cout << "Enter the element to add to the queue:";
			cin >> addel;
			cout << endl;

			PushToQueue(&q_begin, addel);
			system("pause");
			break;
		}
		case 3:
		{
			PopFromQueue(&q_begin);
			system("pause");
			break;
		}
		case 4:
		{
			PrintQueue(q_begin);
			cout << endl;
			system("pause");
			break;
		}
		}
	} while (action_ch != 0);
}

void DemonstrationOfQueue()
{
	cout << "Demonstration of the work of the queue." << endl << endl;

	int choice_qu;
	cout << "Select the data type for the queue elements: \ n";
	cout << "1 - int; 2 - float; 3 - double; 4 - char: ";
	cin >> choice_qu;

	switch (choice_qu)
	{
	case 1:
	{
		Queue<int>* q_begin = (Queue<int>*)NULL;
		ActionsWithQueue(q_begin);
		break;
	}
	case 2:
	{
		Queue<float>* q_begin = (Queue<float>*)NULL;
		ActionsWithQueue(q_begin);
		break;
	}
	case 3:
	{
		Queue<double>* q_begin = (Queue<double>*)NULL;
		ActionsWithQueue(q_begin);
		break;
	}
	case 4:
	{
		Queue<char>* q_begin = (Queue<char>*)NULL;
		ActionsWithQueue(q_begin);
		break;
	}
	default:
	{
		cout << "Ошибочный тип...\n";
		break;
	}
	}
}

/ * ------------------------------------------------ -------------------------------------------------- ----- *
Task: the implementation of stacks and queues.
| ------------------------------------------------- -------------------------------------------------- -----
Main_09.h: demonstration of the program.
| ------------------------------------------------- -------------------------------------------------- -----
| Destination Stack.h: Create the necessary functions for building stacks:
| `function to create a stack;
| `function to display the stack on the screen;
| `function to add the specified email. on the stack;
| `function to remove an item from the stack.
| ------------------------------------------------- -------------------------------------------------- -----
| Assignment Queue.h: Create the necessary functions for building queues:
| `function to create a queue;
| `function to display the queue on the screen;
| `function to add the specified email. in queue;
| `function to remove email. from the queue.
| ------------------------------------------------- -------------------------------------------------- -----
| Note: main_09.h present function to call all the necessary functions of the program with the selected
| user data type (built on templates).
* ------------------------------------------------- -------------------------------------------------- ---- * /
int main_09()
{
	setlocale(LC_ALL, "Russian");
	int sqchoice;

	do
	{
		system ("cls");
		cout << "Choose a subtopic that you would like to work with: \ n";
		cout << "0 - Exit to the main menu \ n";
		cout << "1 - Working with the stack \ n";
		cout << "2 - Working with the queue \ n";
		cout << ">";

		cin >> sqchoice;
		system("cls");

		switch (sqchoice)
		{
		case 1:
		{
			DemonstrationOfStack();
			system("pause");
			break;
		}
		case 2:
		{
			DemonstrationOfQueue();
			system("pause");
			break;
		}
		}
	} while (sqchoice != 0);

	cout << endl;
	system("pause");
	return 0;
}