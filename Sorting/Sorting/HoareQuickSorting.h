#pragma once
#include <iostream>

using namespace std;

void HoareQuickSorting(int* Arr, int startIndex, int endIndex)
{
    //���� ������ ������� <= ������ �����
    if (startIndex <= endIndex)
    {
        int middleElement = Arr[(startIndex + endIndex) / 2]; //������� ������� �������

        //������� ������� ������ � ������� ���������
        int LeftIndex = startIndex; 
        int RightIndex = endIndex;

        while (LeftIndex <= RightIndex) //���� ����� ������ <= �������
        {
            while (Arr[LeftIndex] < middleElement) //���� �������� �� ������ ������� < �������� ��������
                LeftIndex++; //����������� ����� ������

            while (Arr[RightIndex] > middleElement) //���� �������� �� ������� ������� > ������� ��������
                RightIndex--; //��������� ������ ������

            if (LeftIndex <= RightIndex) //���� ����� ������ <= �������
            {
                //������ �������� �� ��� �������
                int tmp = Arr[LeftIndex];
                Arr[LeftIndex] = Arr[RightIndex];
                Arr[RightIndex] = tmp;

                LeftIndex++; //����������� ����� ������
                RightIndex--; //��������� ������ ������
            }
        }

        HoareQuickSorting(Arr, startIndex, RightIndex); //������ � ��������. ������ �� ������, ����� = ������ ������
        HoareQuickSorting(Arr, LeftIndex, endIndex); //������ = ����� ������, ����� �� ������
    }
}

void HoareQuickSorting(pair<int, int>* Arr, int startIndex, int endIndex) //���������� ��� ���� ������ pair<int, int>. �������� ���������� ���������� ����
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
    cout << "����� ������� ���������� �����!" << endl;

    HoareQuickSorting(Arr, 0, Lenght - 1); //��������� �������� � ��������� �������� 0 � �������� ����� �������
}
