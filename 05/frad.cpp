#include "frad.h"

void RandomValuesRadix(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		Arr[i] = rand() % 1000;
	}
}

void PrintArrayRadix(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		cout << Arr[i] << " ";
	}
}

int RadixOfValue(int val)
{
	int count = 0;
	while (val != 0)
	{
		count++;
		val = val / 10;
	}
	return count;
}

int MaxRadix(int *Arr, int quant)
{
	int max = 0;
	int counter = 0;

	for (int i = 0; i < quant; i++)
	{
		if (Arr[i] > max)
			max = Arr[i];
	}

	counter = RadixOfValue(max);
	return counter;
}

void RadixSort(int *Arr, int quant)
{
	int *DopArr = new int[quant];
	int *SortArr = new int[quant];

	int max_rang = MaxRadix(Arr, quant);

	int mod;
	mod = 10;

	int div;
    div = 1;

	int value = 0; //values from 0 to 9

	for (int i = 0; i < max_rang; i++)
	{
		for (int j = 0; j < quant; j++)
		{
			DopArr[j] = (Arr[j] % mod) / div;//(*)
		}

		int z = 0;
		int z1 = -1;

		while (z < quant)
		{
			if (DopArr[z] == value)
			{
				SortArr[z1] = Arr[z];
			}

			if (value != 9 && z == quant - 1)
			{
				z = -1;
				value++;
			}
			z++;
		}

		z = 0;
		z1 = 0;
		value = 0;

		for (int n = 0; n < quant; n++)
		{
			int change = Arr[n];
			Arr[n] = SortArr[n];
			SortArr[n] = change;
		}
		mod = mod * 10;
		div = div * 10;
	}
}
