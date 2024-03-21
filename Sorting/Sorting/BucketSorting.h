#pragma once
#include <iostream>

#include "QuickSorting.h";

using namespace std;

void BucketSorting(int* Arr, int Lenght)
{
	cout << "Метод блочной сортировки!" << endl;

	int mx = Arr[0];
	int mn = Arr[0];

	//Находим минимальный и максимальный элементы
	for (int i = 0; i < Lenght; i++) 
	{
		if (Arr[i] > mx) 
			mx = Arr[i];

		else if (Arr[i] < mn) 
			mn = Arr[i];
	}

	int AmountOfBuckets = abs(mx / 10 - mn / 10 + 1); //Получаем кол-во блоков

	pair<int*, int>* BucketsAndLeghths = new pair<int*, int>[AmountOfBuckets]; //Инициализируем массив блоков

	//Инициализируем блоки
	for (int i = 0; i < AmountOfBuckets; i++)
	{
		BucketsAndLeghths[i].first = new int[Lenght];

		for (int j = 0; j < Lenght; j++)
			BucketsAndLeghths[i].first[j] = 0;

		BucketsAndLeghths[i].second = 0;
	}

	for (int i = 0; i < Lenght; i++)
	{
		int CorrectBucketIndex = abs(Arr[i] / 10 - mn / 10); //Получаем индекс блока, в который стоит положить элемент массива

		pair<int*, int> CorrectBucket = BucketsAndLeghths[CorrectBucketIndex]; //Получаем сам блок

		CorrectBucket.first[CorrectBucket.second] = Arr[i]; //Заносим элемент в блок
		CorrectBucket.second++; //Увеличиваем его длину

		BucketsAndLeghths[CorrectBucketIndex] = CorrectBucket;
	}

	for (int i = 0; i < AmountOfBuckets; i++) //Сортируем каждый блок
		HoareQuickSorting(BucketsAndLeghths[i].first, 0, BucketsAndLeghths[i].second - 1);

	int index = 0;

	for (int i = 0; i < AmountOfBuckets; i++) //По очереди заносим каждый элемент каждого блока обратно в массив
	{
		for (int j = 0; j < BucketsAndLeghths[i].second; j++) 
		{
			Arr[index] = BucketsAndLeghths[i].first[j];
			index++;
		}
	}

	//Чистим память
	for (int i = 0; i < AmountOfBuckets; i++)
		delete[] BucketsAndLeghths[i].first;

	delete[] BucketsAndLeghths;
}

