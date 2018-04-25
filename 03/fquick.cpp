#include "fquick.h"

void RandomValuesQuick(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void PrintArrayQuick(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		cout << Arr[i] << " ";
	}
}

int AverageOfElements(int i, int j)
{
	int average = (i + j) / 2;
	return average;
}

void ExchangeOfElementsQ(int i, int j, int *Arr)
{
	int change = Arr[j];
	Arr[j] = Arr[i];
	Arr[i] = change;
}

void RecursionForSubarrays(int begin, int end, int low_lim, int high_lim, int *Arr)
{
	if (low_lim < end)
	{
		QuickSort(low_lim, end, Arr);
	}

	if (high_lim > begin)
	{	 
		QuickSort(begin, high_lim, Arr);
	}
}

void QuickSort(int low_lim, int high_lim, int *Arr)
{
	//begin|final counters, beginning with:
	int begin = low_lim;//low limit (1 el. of array)
	int end = high_lim;//high limit (end el. of array)

	int key = AverageOfElements(low_lim, high_lim);//reference element index

	while (begin <= end)
	{
		while (Arr[begin] < Arr[key])
		{
			begin++;
		}

		while (Arr[end] > Arr[key])
		{
			end--;
		}

		if (begin <= end)
		{

			if (Arr[begin] > Arr[end])
			{
				ExchangeOfElementsQ(begin, end, Arr);
			}

			begin++;
			if (end > 0) end--;
		}
		RecursionForSubarrays(begin, end, low_lim, high_lim, Arr);
	}
}
