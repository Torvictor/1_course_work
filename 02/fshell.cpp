#include "fshell.h"

void RandomValuesShell(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void PrintArrayShell(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		cout << Arr[i] << " ";
	}
}

void SortShell(int quant, int *Arr)
{
	int curr;
	int step;
	for (step = quant / 2; step > 0; step = step / 2)
	{
		for (int i = step; i < quant; i++)
		{
			for (int j = i - step; j >= 0; j = j - step)
			{
				if (Arr[j] > Arr[j + step])
				{
					curr = Arr[j];
					Arr[j] = Arr[j + step];
					Arr[j + step] = curr;
				}
			}
		}
	}
}
