#include <bits/stdc++.h>
using namespace std;

int selection_sort(int arr[], int n)
{

    for (int i = 0; i < n - 2; i++)
    {
        int min = i;
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }

    int i = 0;
    while (i < n - 2)
    {
        cout << arr[i] << " ";
        i++;
    }
}

int main()
{
    int n;
    // int arr[];
    // cin >> n;
    // cin >> arr[n];
    cin >> n;
    int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // selection_sort(arr[], n);
    selection_sort(arr, n);
}