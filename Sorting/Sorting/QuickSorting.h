#pragma once

void PrintArr(int* Arr, int Length);

void QuickSort(int *Arr, int beginIndex, int endIndex) 
{
    if (beginIndex < endIndex) //Если индекс начала < индекса конца
    {
        int currentIndex = beginIndex; //Задаем текущий индекс массива. Изначально = начальному индексу

        for (int i = currentIndex; i < endIndex; i++)  //Проходим по массиву от начального индекса до конечного
        {
            if (Arr[i] < Arr[endIndex]) //Если текущее значение < значение по конечному индексу
            {
                //Меняем их местами
                int tmp = Arr[i];
                Arr[i] = Arr[currentIndex];
                Arr[currentIndex] = tmp;

                //Увеличиваем текущий индекс
                currentIndex++;
            }
        }

        //Меняем значения по текущему индексу и конечному
        int tmp = Arr[currentIndex];
        Arr[currentIndex] = Arr[endIndex];
        Arr[endIndex] = tmp;

        QuickSort(Arr, beginIndex, currentIndex - 1); // Уходим в рекурсию. Начальный элемент не меняем, конечный - на 1 меньше текущего
        QuickSort(Arr, currentIndex + 1, endIndex); //Начало = текущий индекс + 1. Конец не меняем
    }
}

void QuickSort(int* Arr, int Lenght)
{
    cout << "Метод быстрой сортировки!" << endl;
    QuickSort(Arr, 0, Lenght - 1);
}
