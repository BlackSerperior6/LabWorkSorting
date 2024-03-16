#pragma once

void PrintArr(int* Arr, int Length);

void QuickSort(int *Arr, int beginIndex, int endIndex) 
{
    if (beginIndex < endIndex) 
    {
        int currentIndex = beginIndex;

        for (int i = currentIndex; i < endIndex; i++) 
        {
            if (Arr[i] < Arr[endIndex]) 
            {
                int tmp = Arr[i];
                Arr[i] = Arr[currentIndex];
                Arr[currentIndex] = tmp;
                currentIndex++;
            }
        }

        int tmp = Arr[currentIndex];
        Arr[currentIndex] = Arr[endIndex];
        Arr[endIndex] = tmp;

        QuickSort(Arr, beginIndex, currentIndex - 1);
        QuickSort(Arr, currentIndex + 1, endIndex);
    }
}

void QuickSort(int* Arr, int Lenght)
{
    cout << "Метод быстрой сортировки" << endl;
    QuickSort(Arr, 0, Lenght - 1);
}
