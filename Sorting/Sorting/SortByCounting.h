#pragma once
#include <iostream>

#include "HoareQuickSorting.h"

using namespace std;

pair<int, int> findMaxAndMin(int*Arr, int Lenght) 
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

int GetIndex(pair<int, int>* Arr, int Lenght, int key) 
{
    if (Lenght == 0)
        return -1;

    int index = -1;
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
    cout << "Метод сортировки подсчетом" << endl;

    pair<int, int> MaxAndMin = findMaxAndMin(Arr, Length);

    int CurrentLenght = MaxAndMin.first - MaxAndMin.second + 1;

    pair<int, int>* ElemenstAndTimesMet = new pair<int, int>[CurrentLenght];

    for (int i = 0; i < CurrentLenght; i++)
        ElemenstAndTimesMet[i] = { 0, 0 };

    int FutureLenght = 0;

    for (int i = 0; i < Length; i++)
    {
        int Index = GetIndex(ElemenstAndTimesMet, FutureLenght, Arr[i]);

        if (Index == -1)
        {
            ElemenstAndTimesMet[FutureLenght] = { Arr[i], 1 };
            FutureLenght++;
        }
        else
            ElemenstAndTimesMet[Index].second++;
    }

    CurrentLenght = FutureLenght;

    HoareQuickSorting(ElemenstAndTimesMet, 0, CurrentLenght - 1);

    int IndexOfTheOriginalArray = 0;

    for (int i = 0; i < CurrentLenght; i++)
    {
        pair<int, int> CurrentPair = ElemenstAndTimesMet[i];

        for (int j = 0; j < CurrentPair.second; j++)
        {
            Arr[IndexOfTheOriginalArray] = CurrentPair.first;
            IndexOfTheOriginalArray++;
        }
    }

    delete[] ElemenstAndTimesMet;
}
