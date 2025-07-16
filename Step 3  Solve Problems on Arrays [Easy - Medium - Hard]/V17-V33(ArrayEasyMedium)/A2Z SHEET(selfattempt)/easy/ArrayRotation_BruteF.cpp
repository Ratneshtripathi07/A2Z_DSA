#include <bits/stdc++.h>

using namespace std;

void ArrayRotation(int nums[], int n, int d)
{
    // int arr[n] = nums[n]; // incorrect way to copy array
    // correct way
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = nums[i];
    }
    for (int i = 0; i < n - d; i++) // not n-d-1
    {
        nums[i] = nums[d + i];
    }
    // for (int i = n - d; i < n; i++)
    // {
    //     nums[i] = arr[i - n - d];
    // }

    // Major Bug : nums[i] = arr[i - n - d];
    // is incorrect.

    //     This results in negative indexing like arr[-2],
    //     which causes undefined behavior.

    for (int i = 0; i < d; i++) // i<d not n;
    {
        nums[n - d + i] = arr[i];
    }

    // return nums[n]; // not for void function
}

int main()
{
    int n;
    int d;
    cin >> n;
    cin >> d;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    ArrayRotation(nums, n, d);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
