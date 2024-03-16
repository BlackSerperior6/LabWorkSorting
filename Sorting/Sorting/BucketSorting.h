#pragma once
#include <iostream>

#include "QuickSorting.h";

using namespace std;

void BucketSorting(int* Arr, int Lenght)
{
	cout << "Метод блочной сортировки!" << endl;

	int mx = Arr[0];
	int mn = Arr[0];

	for (int i = 0; i < Lenght; i++) 
	{
		if (Arr[i] > mx) 
			mx = Arr[i];

		else if (Arr[i] < mn) 
			mn = Arr[i];
	}

	int AmountOfBuckets = mx / 10 - mn / 10 + 1;

	pair<int*, int>* BucketsAndLeghths = new pair<int*, int>[AmountOfBuckets];

	for (int i = 0; i < AmountOfBuckets; i++)
	{
		BucketsAndLeghths[i].first = new int[Lenght];

		for (int j = 0; j < Lenght; j++)
			BucketsAndLeghths[i].first[j] = 0;

		BucketsAndLeghths[i].second = 0;
	}

	for (int i = 0; i < Lenght; i++)
	{
		int CorrectBucketIndex = Arr[i] / 10 - mn / 10;

		pair<int*, int> CorrectBucket = BucketsAndLeghths[Arr[i] / 10 - mn / 10];

		CorrectBucket.first[CorrectBucket.second] = Arr[i];
		CorrectBucket.second++;

		BucketsAndLeghths[CorrectBucketIndex] = CorrectBucket;
	}

	for (int i = 0; i < AmountOfBuckets; i++)
		HoareQuickSorting(BucketsAndLeghths[i].first, 0, BucketsAndLeghths[i].second - 1);
		

	int index = 0;
	for (int i = 0; i < AmountOfBuckets; i++) 
	{
		for (int j = 0; j < BucketsAndLeghths[i].second; j++) 
		{
			Arr[index] = BucketsAndLeghths[i].first[j];
			index++;
		}
	}

	for (int i = 0; i < AmountOfBuckets; i++)
		delete[] BucketsAndLeghths[i].first;

	delete[] BucketsAndLeghths;
}

