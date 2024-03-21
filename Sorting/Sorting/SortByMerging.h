#pragma once
#include <iostream>

void Merge(int* Arr, int startIndex, int endIndex, int middleIndex)
{
    int currentLeftIndex = startIndex;
    int currentRightIndex = middleIndex + 1; 

    //Создаем буфферный массив нужной длинный
    int bufferLenght = endIndex - startIndex + 1;
    int* bufferArr = new int[bufferLenght];


    for (int i = 0; i < bufferLenght; i++)
    {
        if (currentLeftIndex <= middleIndex //Если левый индекс <= сердины
            && (currentRightIndex > endIndex || Arr[currentLeftIndex] < Arr[currentRightIndex])) //а также либо правый индекс > конечного, либо значение по левому индексу < значение по правому
        {
            bufferArr[i] = Arr[currentLeftIndex]; //Заносим в буфферный массив значение по левому индексу
            currentLeftIndex++; //Увеличиваем его
        } 
        else //Иначе
        {
            bufferArr[i] = Arr[currentRightIndex]; //Заносим в буфферный массив значение по правому индексу
            currentRightIndex++; //Увеличиваем его
        }
            
    }

    //Заносим в основной массив элементы буфферного массива
    for (int i = 0; i < bufferLenght; i++) 
    {
        Arr[startIndex] = bufferArr[i];
        startIndex++;
    }

    delete[] bufferArr; //Чистим память
}

void SortByMerging(int* Arr, int startIndex, int endIndex)
{
	if (startIndex != endIndex) //Если стартовый элемент != конечному
	{
		int middleIndex = (endIndex + startIndex) / 2; //Находим индекс средний элемент

		SortByMerging(Arr, startIndex, middleIndex); //Уходим в рекурсию. Начало не меняем, конец = индекс среднего элемента
		SortByMerging(Arr, middleIndex + 1, endIndex); //Начало = индекс спреднего элемента + 1. Конец не меняем
		Merge(Arr, startIndex, endIndex, middleIndex); //Сливаем элементы массива по индексу начала и конца
	}
}

void SortByMerging(int* Arr, int Lenght)
{
    cout << "Метод сортировки слиянием!" << endl;
    SortByMerging(Arr, 0, Lenght - 1);
}
