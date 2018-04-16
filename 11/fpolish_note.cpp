#include "proto.h"

StackASY* PushToStackASY(StackASY **begin, const char &add_el)
{
	StackASY* helper = new StackASY;
	helper->elstack = add_el;
	helper->next = *begin;
	*begin = helper;
	return *begin;
}

char PopFromStackASY(StackASY **b)
{
	if (*b == NULL)
		return '\0';

	StackASY *del_el = *b;

	char retdel = NULL;
	retdel = (*b)->elstack;
	*b = del_el->next;

	delete del_el;
	return retdel; 
}

int PriorOfSigns(char sign)
{
	switch (sign)
	{
		//high priority:
	case '*':
	case '/':
		return 3;
		//medium priority:
	case '-':
	case '+':
		return 2;

		//low priority
	case '(':
		return 1;
	}
}

/ * function converts the original string into a reverse Polish entry:
InStr - input string;
OutStr - result (output) line;
outstr_len - the size of the output string;
cur is an element of the type of the StackASY structure for inserting certain characters into the stack.
* /
void ResPolishNote(char* InStr, char* OutStr, int outstr_len, StackASY* cur)
{
	cur = NULL;

	int i = 0;
	while (InStr[i] != '\0')
	{
		// if the next character is ')':
		if (InStr[i] == ')')
		{
			while (cur->elstack != '(')
			{
				OutStr[outstr_len++] = PopFromStackASY(&cur);
			}
			PopFromStackASY(&cur);
		}

		// if another operand character:
		if (InStr[i] >= 'a'&& InStr[i] <= 'z')
		{
			OutStr[outstr_len++] = InStr[i];
		}

		// if the next character is '(':
		if (InStr[i] == '(')
		{
			cur = PushToStackASY(&cur, '(');
		}

		// if the current i-th element of the array is some operator of the following:
		if (InStr[i] == '+' || InStr[i] == '-' || InStr[i] == '*' || InStr[i] == '/')
		{
			if (cur == NULL)
				cur = PushToStackASY(&cur, InStr[i]);

			else

				/ * if the priority of the received operation is higher
				the operation at the top of the stack:
				* /
				if (PriorOfSigns(cur->elstack) < PriorOfSigns(InStr[i]))
				{
					cur = PushToStackASY(&cur, InStr[i]);
				}
				else//else:
				{
					while ((cur != NULL) && (PriorOfSigns(cur->elstack) >= PriorOfSigns(InStr[i])))
					{
						OutStr[outstr_len++] = PopFromStackASY(&cur);
					}

					cur = PushToStackASY(&cur, InStr[i]);
				}
		}
		i++;// move to the next character of the input string
	}

	while (cur != NULL)
	{
		OutStr[outstr_len++] = PopFromStackASY(&cur);
	}

	// discard the unnecessary part:
	OutStr[outstr_len] = '\0';
}