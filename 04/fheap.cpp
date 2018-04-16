#include "fheap.h"

void RandomValuesHeap(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void PrintArrayHeap(int quant, int *Arr)
{
	for (int i = 0; i < quant; i++)
	{
		cout << Arr[i] << " ";
	}
}
void ExchangeOfElementsH(int i, int j, int *Arr)
{
	int change = Arr[j];
	Arr[j] = Arr[i];
	Arr[i] = change;
}

//function for sifting a heap:
void GoToLow(int *Arr, int head, int low)
{
	int max_item;

	bool sort_complite = false;

	while ((head * 2 <= low) && (!sort_complite))
	{
		if (head * 2 == low)
		{
			max_item = head * 2;
		}
		else if (Arr[head * 2] > Arr[head * 2 + 1])
		{
			max_item = head * 2;
		}
		else max_item = head * 2 + 1;

		if (Arr[head] < Arr[max_item])
		{
			ExchangeOfElementsH(max_item, head, Arr);
			head = max_item;
		}
		else
		{
			sort_complite = true; 
		}
	}
}

void HeapSort(int *Arr, int quant)
{
	for (int i = (quant / 2) - 1; i >= 0; i--)
	{
		/*
		для каждого i-го элемента нижнего ряда с помощью функции просеивания кучи
		будем следить за позициями родителей и их потомков (сравнивать их)
		=> сформируем нижний ряд пирамиды:
		*/
		GoToLow(Arr, i, quant);
	}
	for (int j = quant - 1; j >= 1; j--)
	{
		int curr = Arr[0];
		Arr[0] = Arr[j];
		Arr[j] = curr;
		GoToLow(Arr, 0, j - 1);
	}
}