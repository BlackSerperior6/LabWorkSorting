#include <iostream>

using namespace std;

#include "SortByMerging.h";
#include "HoareQuickSorting.h"
#include "SortByCounting.h"
#include "BucketSorting.h"
#include "ShellSort.h"
#include "QuickSorting.h"
#include "NaturalMerge.h"

typedef void(*functionPointer)(int*, int);

void PrintArr(int* Arr, int Length) 
{
	if (Length == 0)
	{
		cout << "Массив пуст" << endl;
		return;
	}
		

	cout << Arr[0];

	for (int i = 1; i < Length; i++)
		cout << " " << Arr[i];

	cout << endl;
};

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	functionPointer functions[] = {&SortByMerging, &SortByCounting, &BucketSorting, &HoareQuickSorting, &ShellsSort, &QuickSort, &SortUsingNaturalMerge};

	cout << "----------------------------------------" << endl;

	for (functionPointer function : functions)
	{
		int Lenght;

		do
		{
			cout << "Режим генерации случайных элементов. Сколько должно быть элементов? Должно быть > 1" << endl;
			cin >> Lenght;
		}
		while (Lenght <= 1);

		int *Arr = new int[Lenght];

		for (int i = 0; i < Lenght; i++)
			Arr[i] = rand() % 100;

		cout << "Неосортированый массив: " << endl;

		PrintArr(Arr, Lenght);

		function(Arr, Lenght);

		cout << "Отсортированый массив: " << endl;

		PrintArr(Arr, Lenght);

		do
		{
			cout << "Режим задавания элементов вручную. Сколько должно быть элементов? Должно быть > 1" << endl;
			cin >> Lenght;
		} 
		while (Lenght <= 1);

		delete[] Arr;

		Arr = new int[Lenght];

		cout << "Начинайте поочереди вводить элементы по одному" << endl;

		for (int i = 0; i < Lenght; i++)
			cin >> Arr[i];

		function(Arr, Lenght);

		cout << "Отсортированый массив: " << endl;

		PrintArr(Arr, Lenght);

		delete[] Arr;

		cout << "----------------------------------------" << endl;
	}
}
