#include <iostream>

using namespace std;

void QuickSort(int *Arr, int startIndex, int endIndex) 
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

        QuickSort(Arr, startIndex, Right);
        QuickSort(Arr, Left, endIndex);
    }  
}

int main()
{
    srand(time(0));
    int n;
    cin >> n;

    int *Arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        int elm = rand() % 100;
        Arr[i] = elm;
        cout << elm << " ";
    }

    QuickSort(Arr, 0, n - 1);

    cout << endl;

    for (int i = 0; i < n; i++)
        cout << Arr[i] << " ";

    delete[] Arr;
}