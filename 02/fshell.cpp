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

	/*
	Шаг разбиения step - равен половине размера массива и больше нуля,
	так как иначе (если не > 0) массив уже явл. упорядоченным.
	После каждой итерации данного цикла шаг делим пополам до тех пор,
	пока он не будет равен 1 (ведь это будет означать, что мы рассмотрели весь
	массив как единую группу):
	*/
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