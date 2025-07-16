// #include <bits/stdc++.h>
// using namespace std;

// void mergesort(int arr[], int l, int h)
// {

//     /**
//      * @brief use of Merge Sorting algorithm
//      * @param l, m, h : low mid high
//      */

//     // base case
//     if (l == h)
//     {
//         return;
//     }
//     int m = (l + h) / 2;
//     mergesort(arr, l, m);     // recursive
//     mergesort(arr, m + 1, h); // recursive
//     merge(arr, l, m, h);
// }

// void merge(int arr[], int l, int m, int h)
// {

//     vector<int> ss; // sorted subarray
//     // pointers
//     int i = l;
//     int j = m + 1;

//     // merge logic

//     while (i <= m && j <= h)
//     {
//         if (arr[i] < arr[j])
//         {
//             ss.push_back(arr[i]);
//             i++;
//         }
//         else
//             ss.push_back(arr[j]);
//         j++;
//     }

//     // element remaining to be pushed due to one of the conditions[i <= m && j <= h]
//     // getting void leading to loop break.

//     while (i <= m) // for left half
//     {
//         ss.push_back(arr[i]);
//         i++;
//     }

//     while (j <= h) // for right half
//     {
//         ss.push_back(arr[i]);
//         j++;
//     }

//     // copy the temporary array to original

//     for (int k = 0; k < h; k++)
//     {
//         arr[l + k] = ss[k];
//     }
// }

// int main()
// {

//     int n;
//     cin >> n;
//     int arr[n];

//     // input into the array
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // calling ms fn
//     mergesort(arr, 0, n - 1);

//     // print sorted array
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// ----------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
    vector<int> ss; // sorted subarray
    // pointers
    int i = l;
    int j = m + 1;

    // merge logic
    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            ss.push_back(arr[i]);
            i++;
        }
        else
        {
            ss.push_back(arr[j]);
            j++;
        }
    }

    // element remaining to be pushed due to one of the conditions [i <= m && j <= h]
    // getting void leading to loop break.

    while (i <= m)
    { // for left half
        ss.push_back(arr[i]);
        i++;
    }

    while (j <= h)
    {                         // for right half
        ss.push_back(arr[j]); // Corrected: should be arr[j] not arr[i]
        j++;
    }

    // copy the temporary array to original
    // Iterate from 0 up to the size of the temporary sorted subarray
    for (int k = 0; k < ss.size(); k++)
    {
        arr[l + k] = ss[k];
    }
}

void mergesort(int arr[], int l, int h)
{
    /**
     * @brief use of Merge Sorting algorithm
     * @param l, m, h : low mid high
     */

    // base case
    if (l >= h)
    { // Changed l == h to l >= h to handle single-element or invalid ranges
        return;
    }
    int m = l + (h - l) / 2;  // More robust way to calculate mid to prevent overflow for large l, h
    mergesort(arr, l, m);     // recursive for left half
    mergesort(arr, m + 1, h); // recursive for right half
    merge(arr, l, m, h);      // merge the sorted halves
}

int main()
{
    int n;
    cin >> n;
    // Using a dynamic array or std::vector is safer than VLA (variable-length array)
    // int arr[n]; is a GCC extension and not standard C++
    vector<int> arr(n); // Recommended: Use std::vector for dynamic arrays

    // input into the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // calling mergesort fn
    // Pass arr.data() for std::vector when using raw array function signatures
    mergesort(arr.data(), 0, n - 1);

    // print sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0; // Indicate successful execution
}