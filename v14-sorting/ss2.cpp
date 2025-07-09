#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    // ai gen main/driver function

    /*
     * This program reads an integer n from standard input, followed by n integers.
     * It then sorts the array using selection sort and prints the sorted array.
     */

    int n;    // Number of elements in the array
    cin >> n; // Read the size of the array

    int arr[n]; // Declare an array of size n

    // Read n integers into the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sort the array using selection sort
    selection_sort(arr, n);

    // Output the sorted array, separated by spaces
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "😁";
    }
    cout << endl; // Print a newline at the end
}