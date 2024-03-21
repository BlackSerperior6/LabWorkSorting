#pragma once
#include <iostream>

using namespace std;

void HoareQuickSorting(int* Arr, int startIndex, int endIndex)
{
    //Если индекс начался <= индекс конца
    if (startIndex <= endIndex)
    {
        int middleElement = Arr[(startIndex + endIndex) / 2]; //Находим средний элемент

        //Заводим индексы левого и правого элементов
        int LeftIndex = startIndex; 
        int RightIndex = endIndex;

        while (LeftIndex <= RightIndex) //Пока левый индекс <= правого
        {
            while (Arr[LeftIndex] < middleElement) //Пока значение по левому индексу < среднего элемента
                LeftIndex++; //Увеличиваем левый индекс

            while (Arr[RightIndex] > middleElement) //Пока значение по правому индексу > среднее значение
                RightIndex--; //Уменьшаем правый индекс

            if (LeftIndex <= RightIndex) //Если левый индекс <= правого
            {
                //Меняем значение по ним местами
                int tmp = Arr[LeftIndex];
                Arr[LeftIndex] = Arr[RightIndex];
                Arr[RightIndex] = tmp;

                LeftIndex++; //Увеличиваем левый индекс
                RightIndex--; //Уменьшаем правый индекс
            }
        }

        HoareQuickSorting(Arr, startIndex, RightIndex); //Уходим в рекурсию. Начало не меняем, конец = правый индекс
        HoareQuickSorting(Arr, LeftIndex, endIndex); //Начало = левый индекс, конец не меняем
    }
}

void HoareQuickSorting(pair<int, int>* Arr, int startIndex, int endIndex) //Перегрузка для типа данных pair<int, int>. Работает аналогично перегрузке выше
{
    if (startIndex <= endIndex)
    {
        int middleElement = Arr[(startIndex + endIndex) / 2].first;

        int LeftIndex = startIndex;
        int RightIndex = endIndex;

        while (LeftIndex <= RightIndex)
        {
            while (Arr[LeftIndex].first < middleElement)
                LeftIndex++;

            while (Arr[RightIndex].first > middleElement)
                RightIndex--;

            if (LeftIndex <= RightIndex)
            {
                pair<int, int> tmp = Arr[LeftIndex];
                Arr[LeftIndex] = Arr[RightIndex];
                Arr[RightIndex] = tmp;
                LeftIndex++;
                RightIndex--;
            }
        }

        HoareQuickSorting(Arr, startIndex, RightIndex);
        HoareQuickSorting(Arr, LeftIndex, endIndex);
    }
}

void HoareQuickSorting(int *Arr, int Lenght) 
{
    cout << "Метод быстрой сортировки Хоара!" << endl;

    HoareQuickSorting(Arr, 0, Lenght - 1); //Запускаем рекурсию с начальным индексом 0 и индексом конца массива
}
