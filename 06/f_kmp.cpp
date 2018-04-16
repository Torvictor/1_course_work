#include "f_kmp.h"

void PrintArrayKMP(int *Arr, int quant)
{
	for (int i = 0; i < quant; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

void PrefixFunction(char* str, int* Array, int length)
{
	int n = 0;
	Array[0] = 0;

	for (int i = 1; i < length; i++)
	{

		while ((n > 0) && (str[n] != str[i]))
		{

			n = Array[n - 1];
		}

		if (str[n] == str[i])
		{

			n++;
		}
		Array[i] = n;
	}
}

void Combination(char* str, char* text, char* common_str, int common_len)
{
	strcpy_s(common_str, common_len + 1, str);
	strcat_s(common_str, common_len + 1, "|");
	strcat_s(common_str, common_len + 1, text);
}

void KMP_Search(char* str, int str_len, int common_len, int* PrefixArr)
{
	int pos = -1;

	/*
	elementwise we go through a combined (common) line,
	starting with the position after the symbol '|' - separator:
	*/
	for (int i = str_len + 2; i <= common_len; i++)
	{
		if (str_len == PrefixArr[i])
		{
			pos = i - str_len - strlen(str + 1);
			cout << "Number of position: " << pos << endl;
		}
	}
	if (pos == (-1)) cout << "No rows were found!" << endl;
}