#pragma once
#include <iostream>

using namespace std;

void ShellsSort(int *Arr, int lenght) 
{
    cout << "����� ���������� �����!" << endl;

    for (int step = lenght / 2; step > 0; step /= 2) //�������� ���, ������ ������ ������� /2. �������� ����, ������� ����� ������� ���� ��� > 0. ����� ������� ������� ����� ��� �� 2
    {
        for (int i = step; i < lenght; ++i)  //��� ���� ����. ������ �� ������� �� ���� �� ������ �������
        {
            int current_index = i - step; //�������� ������ ��������, ������� ����� ����������

            while (current_index >= 0 && Arr[current_index] > Arr[current_index + step]) //���� ������ ������ ������ ��� ����� 0 � ��� ���� �������� �� ���� ������, ��� �� ���� + ���
            {
                //������ �������� �� ����������� ��������, � �� ������������ ������ + ��� �������
                int tmp = Arr[current_index + step];
                Arr[current_index + step] = Arr[current_index];
                Arr[current_index] = tmp;

                current_index -= step; //���������� ������ ������������� �������� �� ���
            }
        }
    }
}
