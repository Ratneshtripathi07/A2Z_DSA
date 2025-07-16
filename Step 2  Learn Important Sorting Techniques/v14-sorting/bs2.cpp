// BubbleSort.cpp code was correct

#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int didSwap = 0; // optimisation if array is already sorted
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
        // cout << "it's reunning" << endl; // optional debug, can comment out
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
    cout << endl;
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

// this bubble sort algo has time complexity of O(n^2) // worst case
// if sorted array, its 0(1)