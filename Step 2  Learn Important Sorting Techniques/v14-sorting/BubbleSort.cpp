#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int didSwap = 0; // optimisation if array is already sorted
        // for (int j = 0; j < n - i - 1; i++) //bs2.cpp due to this blunt mistake
        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;
        cout << "it's running" << endl;
    }
}

void readarray(int arr[], int n)
{
    // int n;
    // cin >> n;
    // int arr[n]; // not needed
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    readarray(arr, n);
    bubblesort(arr, n);
    printarray(arr, n);
}