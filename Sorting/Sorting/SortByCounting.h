#pragma once
#include <iostream>

#include "HoareQuickSorting.h"

using namespace std;

pair<int, int> findMaxAndMin(int*Arr, int Lenght) //Метод для нахождения максимума и мимнимума в массиве
{
    pair<int, int> MaxAndMin = {Arr[0], Arr[0]};

    for (int i = 1; i < Lenght; i++)
    {
        if (Arr[i] > MaxAndMin.first)
            MaxAndMin.first = Arr[i];

        else if (Arr[i] < MaxAndMin.second)
            MaxAndMin.second = Arr[i];
    }

    return MaxAndMin;
}

int GetIndex(pair<int, int>* Arr, int Lenght, int key) //Метод для нахождения нужного индекса в массиве пар по ключу
{
    if (Lenght == 0)
        return -1;

    int index = -1; //Если ничего не нашли, то вернем -1
    bool flag = false;
    
    for (int i = 0; i < Lenght && !flag; i++)
    {
        flag = Arr[i].first == key;

        if (flag)
            index = i;
    }

    return index;
}

void SortByCounting(int* Arr, int Length) 
{
    cout << "Метод сортировки подсчетом!" << endl;

    pair<int, int> MaxAndMin = findMaxAndMin(Arr, Length); //Получаем максимум и минимум

    int CurrentLenght = MaxAndMin.first - MaxAndMin.second + 1; //Получаем длинну будущего массива пар

    pair<int, int>* ElemenstAndTimesMet = new pair<int, int>[CurrentLenght]; //Создаем массив пар. Элемент 1 = само число, элемент 2 - сколько раз встретилось

    for (int i = 0; i < CurrentLenght; i++)
        ElemenstAndTimesMet[i] = { 0, 0 }; //Инициализация

    int FutureLenght = 0; //Рассчет будущей длинный массива пар

    for (int i = 0; i < Length; i++) // Проходим по массиву
    {
        int Index = GetIndex(ElemenstAndTimesMet, FutureLenght, Arr[i]); //Пытаемся получить индекс пары в массиве пар, в которой числом является текущий элемент массива

        if (Index == -1) //Если не нашли
        {
            ElemenstAndTimesMet[FutureLenght] = { Arr[i], 1 }; //Заносим в массив пар с кол-вом встречь = 1
            FutureLenght++; //Увеличиваем будущую длинну массива
        }
        else
            ElemenstAndTimesMet[Index].second++; //Иначе просто увеличиваем кол-во встречь по элементу по найденному индексу
    }

    CurrentLenght = FutureLenght; //Текущая длинна = будущая

    HoareQuickSorting(ElemenstAndTimesMet, 0, CurrentLenght - 1); //Сортируем массив пар быстрой сортировкой Хоара

    int IndexOfTheOriginalArray = 0;

    for (int i = 0; i < CurrentLenght; i++) //Проходим по массиву пар
    {
        pair<int, int> CurrentPair = ElemenstAndTimesMet[i]; //Берем пару

        for (int j = 0; j < CurrentPair.second; j++) //Заносим её элемент в массив столько раз, сколько он встретился
        {
            Arr[IndexOfTheOriginalArray] = CurrentPair.first;
            IndexOfTheOriginalArray++;
        }
    }

    delete[] ElemenstAndTimesMet; //Чистим память
}
