#pragma once
#include <iostream>

using namespace std;

void HoareQuickSorting(int* Arr, int startIndex, int endIndex)
{
    if (startIndex <= endIndex)
    {
        int middle = Arr[(startIndex + endIndex) / 2];

        int Left = startIndex;
        int Right = endIndex;

        while (Left <= Right)
        {
            while (Arr[Left] < middle)
                Left++;

            while (Arr[Right] > middle)
                Right--;

            if (Left <= Right)
            {
                int tmp = Arr[Left];
                Arr[Left] = Arr[Right];
                Arr[Right] = tmp;
                Left++;
                Right--;
            }
        }

        HoareQuickSorting(Arr, startIndex, Right);
        HoareQuickSorting(Arr, Left, endIndex);
    }
}

void HoareQuickSorting(pair<int, int>* Arr, int startIndex, int endIndex)
{
    if (startIndex <= endIndex)
    {
        int middle = Arr[(startIndex + endIndex) / 2].first;

        int Left = startIndex;
        int Right = endIndex;

        while (Left <= Right)
        {
            while (Arr[Left].first < middle)
                Left++;

            while (Arr[Right].first > middle)
                Right--;

            if (Left <= Right)
            {
                pair<int, int> tmp = Arr[Left];
                Arr[Left] = Arr[Right];
                Arr[Right] = tmp;
                Left++;
                Right--;
            }
        }

        HoareQuickSorting(Arr, startIndex, Right);
        HoareQuickSorting(Arr, Left, endIndex);
    }
}

void HoareQuickSorting(int *Arr, int Lenght) 
{
    cout << "Метод быстрой сортировки Хоара!" << endl;

    HoareQuickSorting(Arr, 0, Lenght - 1);
}
