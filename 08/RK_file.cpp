#include "RK_file.h"

void PrintArrayRK(int *Arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

/ *
hash function:
`based on the received integer" ASCII "codes from the template symbols
gives the obtained value in the 100th number system.
* /
unsigned long int HashFunc(char* templ, int templ_len, int* Code)
{
	for (int i = 0; i < templ_len; i++)
	{
		// write the "ASCII" code of the i-th character in the template:
		Code[i] = (int)templ[i];
	}

	int p;// the degree of the number 100
	p = 0;

	// value of the sum of all "ASCII" character codes of the template in 100 SS:
	unsigned long int value;
	value = 0;

	for (int j = templ_len - 1; j >= 0; j--)
	{
		// translation into 100 SS:
		value = value + Code[j] * pow(100, p);

		p++;// increase the degree of the number 100
	}
	return value;
}

// recalculation of the hash function:
unsigned long int HashRecalculation(int templ_len, unsigned long int hash_value, int del_symb, int add_symb)
{
	/ *
	add the current hash value
	the code "ASCII" of the symbol added to 100 SS:
	* /
	hash_value = hash_value * 100 + add_symb;

	// then subtract the "ASCII" code of the old character in 100 SS:
	hash_value = hash_value - del_symb * pow(100, templ_len);

	return hash_value;
}

/ *
for the given start_pos function extracts the required substring from the text:
(start_pos is the position with which the substring is requested from the text!)
* /
char* TakeSubText(int start_pos, int templ_len, char* text)
{
	char* subtext = new char[templ_len];

	int j = 0;
	while (j < templ_len)
	{
		subtext[j] = text[start_pos];

		start_pos++;
		j++;
	}
	subtext[j] = 0;

	return subtext;
}

/ *
Search for Rabin-Karp.
Function parameters:
`text - source text
`templ - the template you are looking for
`text_len - length of source text
`templ_len - the length of the template to search for
`hash_templ - the result of the hash function for the template
`Result - record the result of work of this function (entries of entries)
`size - the size of the array Result.
* /
int RabinKarp_Search(char* text, int text_len, char* templ, int templ_len, unsigned long int hash_templ, int* Result, int size)
{
	int i = 0;//steps on the text
	int j = 0;//steps on the teamplate
	int find_pos = 0;// the index of the occurrence of the template in the source text
	bool flag = false;// signal that there are occurrences

	unsigned long int hash_subtext;
	char* subtext = new char[templ_len];
	int* Code_subtext = new int[templ_len];

	subtext = TakeSubText(0, templ_len, text);
	hash_subtext = HashFunc(subtext, templ_len, Code_subtext);
	int add_symb, del_symb;

	while (i < text_len)
	{
		/ *
		if the hash value of the taken substring from the text
		matches the value of the template hash function:
		* /
		if (hash_subtext == hash_templ)
		{
			j = 0; // get to the starting position in the template
			find_pos = i; // remember this occurrence of the pattern in the text
			int step = 0; // shows how many steps were passed
			// both in the text and in the template

			// if the current characters of the text and pattern match:
			while (text[i] == templ[j] && j < templ_len)
			{
				j ++; // step on the next character of the template
				i ++; // step to the next character of the text
				step++;//count of steps by characters
			}

			/ * if the number of steps by symbols
			coincided with the length of the template:
			* /
			if (step == templ_len)
			{
				Result[size] = find_pos;
				size++;

				subtext = TakeSubText(i, templ_len, text);

				hash_subtext = HashFunc(subtext, templ_len, Code_subtext);

				flag = true;
			}
		}
		else i++;// Otherwise we move forward along the text by one

		// if no entries were found:
		if (flag == false)
		{
			/ *
			consider the code of the first character from the taken substring:
			(which will be subtracted from the value below
			hash function of the next substring)
			* /
			del_symb = (int)subtext[0];

			subtext = TakeSubText(i, templ_len, text);

			/ *
			consider the code of the last character from the new one
			substring (which will be processed by the hash function
			and added to the hash value of this substring):
			* /
			add_symb = (int)subtext[templ_len - 1];

			hash_subtext = HashRecalculation(templ_len, hash_subtext, del_symb, add_symb);
		}

		flag = false;// deactivate the flag
	}

	return size; // return the size of the result array
	// required for further output of the result of RK-search
}

void PrintResultRK(int* Result, int size)
{
	if (size == 0)
	{
		cout << "Entering substring was not found!" << endl;
	}
	else
	{
		cout << "Positions of the occurrences of substrings found in the text:";
		PrintArrayRK(Result, size);
		cout << endl;
	}
}