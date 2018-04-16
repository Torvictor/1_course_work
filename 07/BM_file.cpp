#include "BM_header.h"	

int BMsearch(char *text, char *templ, int text_len, int templ_len, int *Result)
{
	int *SuffTab = CreateSuffixTable(templ, templ_len);	
	int *StopTab = CreateStopTable(templ, templ_len);					
	int size = 0;
	int i = templ_len - 1;

	while (i < text_len)									
	{
		int tmsuff_len = 0;
		int y = templ_len - 1;
		int x = i;

		while(templ[y] == text[x] && x >= 0)						
		{
			tmsuff_len++;
			x--;
			y--;
		}

		if (tmsuff_len == templ_len)											
		{
			Result[size] = i - templ_len + 2;
			i++;//сдвиг вперёд
			size++;та
		}
		else																
		{
			int step = y - StopTab[text[x] - 32];//текуший шаг

			if (step > SuffTab[tmsuff_len])								
			{
				i = i + step;
			}
			else												
			{
				i = i + SuffTab[tmsuff_len];
			}
		}
	}
	return size;
}

void PrintArrBM(int *Arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Entry found: " << Arr[i] << endl;
	}
}

/ *
create a suffix-table of shifts
(calculation of all possible shifts of the template
for all possible suffixes):
* /
int *CreateSuffixTable(char *templ, int templ_len)
{
	int *SuffTab = new int[templ_len + 1];
	SuffTab[0] = 1;

	for (int i = 1; i < templ_len + 1; i++)									
	{
		bool detect_suff = true;

		for (int j = templ_len - 2; j >= i - 1 && detect_suff != true; j--)		
		{
			int h = templ_len - 1;

			while (j - i < templ_len - 1 - j && detect_suff != false)			
			{
				if (templ[j] != templ[h])									
				{
					detect_suff = false;
				}
				j--;
				h--;
			}
			if (templ[j] == templ[h])										
			{
				detect_suff = false;
			}	

			if (detect_suff == true)									
			{
				SuffTab[i] = templ_len - 1 - j;
			}
		}

		if (detect_suff == false)											
		{
			SuffTab[i] = SuffTab[i - 1];
		}
	}
	return SuffTab;
}

/ * search for the rightmost position
A non-matched character in the template:
* /
int FindPosBM(char *templ, int templ_len, char symbol)
{
	int pos = 0;
	bool detected = false;
	for (int i = templ_len - 1; i >= 0 && detected == false; i--)				
	{
		if (templ[i] == symbol)									
		{
			detected = true;
			pos = i;
		}
	}
	if (detected == false)												
	{
		pos = -1;
	}
	return pos;
}

int *CreateStopTable(char *templ, int templ_len)
{
	int *StopTab = new int[95];

	// search for the right occurrence of each of the alphabet characters:
	for (char symbol = 32; symbol < 127; symbol++)									
	{
		StopTab[symbol - 32] = FindPosBM(templ, templ_len, symbol);					
	}
	return StopTab;
}