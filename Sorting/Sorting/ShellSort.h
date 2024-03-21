#pragma once
#include <iostream>

using namespace std;

void ShellsSort(int *Arr, int lenght) 
{
    cout << "Метод сортировки Шелла!" << endl;

    for (int step = lenght / 2; step > 0; step /= 2) //Получаем шаг, равный длинне массива /2. Начинаем цикл, который будет длиться пока шаг > 0. После каждого прохода делим шаг на 2
    {
        for (int i = step; i < lenght; ++i)  //Еще один цикл. Проход по массиву от шага до длинны массива
        {
            int current_index = i - step; //Получаем индекс элемента, который будем сравнивать

            while (current_index >= 0 && Arr[current_index] > Arr[current_index + step]) //Пока данный индекс больше или равен 0 и при этом значение по нему больше, чем по нему + шаг
            {
                //Меняем значение по сравниваему элементу, и по сравниваемый индекс + шаг местами
                int tmp = Arr[current_index + step];
                Arr[current_index + step] = Arr[current_index];
                Arr[current_index] = tmp;

                current_index -= step; //Уменьшамем индекс сравниваемого элемента на шаг
            }
        }
    }
}
