#include "ball-massive.h"

void PrintMas(int quant, int *mas)
{
	for (int i = 0; i < quant; i++)
	{
		cout << mas[i] << " ";
	}
}

//array sorting by bubble method:
void SortMas(int quant, int *mas)
{
	int curr;

	for (int i = 1; i < quant; i++)
	{
		for(int j = 0; j < quant - i; j++)
		{
			if (mas[j] < mas[j+1])
			{
				curr = mas[j];
				mas[j] = mas[j+1];
				mas[j+1]=curr;
			}
		}
	}
}	

