#pragma once
#include <iostream>

void Merge(int* Arr, int startIndex, int endIndex, int middleIndex)
{
    int currentLeftIndex = startIndex;
    int currentRightIndex = middleIndex + 1;
    int bufferLenght = endIndex - startIndex + 1;
    int* bufferArr = new int[bufferLenght];

    for (int i = 0; i < bufferLenght; i++)
    {
        if (currentLeftIndex <= middleIndex 
            && (currentRightIndex > endIndex || Arr[currentLeftIndex] < Arr[currentRightIndex]))
        {
            bufferArr[i] = Arr[currentLeftIndex];
            currentLeftIndex++;
        } 
        else
        {
            bufferArr[i] = Arr[currentRightIndex];
            currentRightIndex++;
        }
            
    }

    for (int i = 0; i < bufferLenght; i++) 
    {
        Arr[startIndex] = bufferArr[i];
        startIndex++;
    }

    delete[] bufferArr;
}

void SortByMerging(int* Arr, int startIndex, int endIndex)
{
	if (startIndex != endIndex)
	{
		int middleIndex = (endIndex + startIndex) / 2;

		SortByMerging(Arr, startIndex, middleIndex);
		SortByMerging(Arr, middleIndex + 1, endIndex);
		Merge(Arr, startIndex, endIndex, middleIndex);
	}
}

void SortByMerging(int* Arr, int Lenght)
{
    cout << "Метод сортировки слиянием!" << endl;
    SortByMerging(Arr, 0, Lenght - 1);
}
