#include <iostream>
#include <chrono>

using namespace std;

#include "SortByMerging.h";
#include "HoareQuickSorting.h"
#include "SortByCounting.h"
#include "BucketSorting.h"
#include "ShellSort.h"
#include "QuickSorting.h"

typedef void(*functionPointer)(int*, int);

void PrintArr(int* Arr, int Length) //Метод печати массива
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

	functionPointer functions[] = {&SortByMerging, &SortByCounting, &HoareQuickSorting, &ShellsSort, &QuickSort, &BucketSorting}; //Машина состояний со всеми методами сортировки

	cout << "----------------------------------------" << endl;

	for (functionPointer function : functions) //Цикл for, проходящий по каждой функции
	{
		int Lenght;
		chrono::steady_clock::time_point start, end;

		do //Пользователь задает длинну
		{
			cout << "Режим генерации случайных элементов. Сколько должно быть элементов? Должно быть > 1" << endl;
			cin >> Lenght;
		}
		while (Lenght <= 1); //Пока не задаст нужную

		int *Arr = new int[Lenght]; //Инициализируем массив, который будем сортировать

		for (int i = 0; i < Lenght; i++)
			Arr[i] = rand() % 100; //Заполняем его случайными числами

		cout << "Неотсортированый массив: " << endl;

		PrintArr(Arr, Lenght); //Печатаем неотсортированный массив

		start = chrono::high_resolution_clock::now();
		function(Arr, Lenght); //Сортируем
		end = chrono::high_resolution_clock::now();

		cout << "Отсортированый массив: " << endl;

		PrintArr(Arr, Lenght); //Вновь печатаем
		cout << "Время выполнения сортировки: " << (end - start).count() << endl;

		do //Вновь получаем длинну от пользователя
		{
			cout << "Режим задавания элементов вручную. Сколько должно быть элементов? Должно быть > 1" << endl;
			cin >> Lenght;
		} 
		while (Lenght <= 1);

		delete[] Arr; //Очищаем предыдущие содержание массива

		Arr = new int[Lenght]; //Задаем его по новой

		cout << "Начинайте поочереди вводить элементы по одному" << endl;

		for (int i = 0; i < Lenght; i++)
			cin >> Arr[i]; //В этот раз пользователь сам вводит числа

		start = chrono::high_resolution_clock::now();
		function(Arr, Lenght); //Сортируем
		end = chrono::high_resolution_clock::now();

		cout << "Отсортированый массив: " << endl;

		PrintArr(Arr, Lenght); //Вновь печатаем
		cout << "Время выполнения сортировки: " << (end - start).count() << endl;

		delete[] Arr; //Чистим память

		cout << "----------------------------------------" << endl;
	}
}
