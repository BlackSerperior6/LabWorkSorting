#pragma once

#include <iostream>

using namespace std;

void NaturalMerge(int *Arr, int startIndex, int endIndex)
{
	for (int i = 0; i < endIndex - startIndex; i++)
	{
		for (int j = 0; j < endIndex - startIndex - i; j++) 
		{
			if (Arr[j] > Arr[j + 1]) 
			{
				int tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
			}
		}
	}
}

void RemoveElement(pair<int, int> *Arr, int Index, int Lenght)
{
	for (int i = Index; i < Lenght - 1; i++)
		Arr[i] = Arr[i + 1];
}

void SortUsingNaturalMerge(int *Arr, int Lenght) 
{
	cout << "Сортировка методом натурального слияния" << endl;

	pair<int, int>* SeriesIndexes = new pair<int, int>[Lenght];
	int countOfPairs = 0;
	int lastFirsIndex = 0;

	for (int i = 0; i < Lenght; i++)
	{
		if (i == Lenght - 1 || Arr[i] > Arr[i + 1])
		{
			SeriesIndexes[countOfPairs] = { lastFirsIndex, i };
			countOfPairs++;
			lastFirsIndex = i + 1;
		}
	}

	while (countOfPairs > 1)
	{
		for (int i = 0; i < countOfPairs - 1; i++)
		{
			NaturalMerge(Arr, SeriesIndexes[i].first, SeriesIndexes[i + 1].second);
			SeriesIndexes[i].second = SeriesIndexes[i + 1].second;
			RemoveElement(SeriesIndexes, i + 1, countOfPairs);
			countOfPairs--;
		}
	}

	delete[] SeriesIndexes;
}
