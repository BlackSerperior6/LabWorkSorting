#include <iostream>

using namespace std;


int iterationsCounter = 0;

void printArr(int* Arr, int startIndex, int endIndex) 
{
	for (int i = startIndex; i < endIndex + 1; i++)
		cout << Arr[i] << " ";

	cout << endl;
};

void Merge(int* Arr, int start, int end)
{
	int Lenght = end - start;

	for (int i = start; i < Lenght; i++)
	{
		for (int j = start; j < Lenght; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j + 1];
				Arr[j + 1] = Arr[j];
				Arr[j] = tmp;
			}
		}
	}

}

void Sort(int *Arr, int start, int end, int parentID) 
{
	int id = ++iterationsCounter;
	cout << "-----------------------" << endl;
	cout << "Создание новой итерации с ID = " << id << ", ID родителя = " << parentID << endl;
	cout << "Начальный индекс блока массива = " << start << " конечный = " << end << endl << endl;
	cout << "Текущий блок массива: " << endl;
	printArr(Arr, start, end);

	if (start != end)
	{
		int middleIndex = (end + start) / 2;
		Sort(Arr, start, middleIndex, id);
		Sort(Arr, middleIndex + 1, end, id);
		cout << "Объединяем 2 блока массива: " << endl;
		Merge(Arr, start, end);

		printArr(Arr, start, middleIndex);
		cout << "  " << endl;
		printArr(Arr, middleIndex + 1, end);
		cout << "Результат: " << endl;
		printArr(Arr, start, end);
	}
	else
	{
		cout << endl <<"Обнаружен блок массива с одним элементом, возвращаемся в предыдущую итерацию с id = " << parentID << endl;
		cout << "-----------------------" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int n;

	cout << "Введите кол-во элементов массива" << endl;

	cin >> n;

	if (n <= 1)
	{
		cout << "Кол во элементов массива должно быть >=1" << endl;
		return 0;
	}

	int* Arr = new int[n];

	cout << endl << "Ваш массив:" << endl;

	for (int i = 0; i < n; i++)
	{
		int elm = rand() % 100;
		Arr[i] = elm;
		cout << elm << " ";
	}

	cout << endl;

	Sort(Arr, 0, n - 1, 0);

	cout << endl << endl <<"Отсортированны массив:" << endl;

	printArr(Arr, 0, n - 1);

	delete[] Arr;
}
