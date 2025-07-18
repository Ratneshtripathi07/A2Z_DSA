#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> arr)
{
    if (arr.size() < 2)
        return -1;

    int first = arr[0];
    // largest element
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > first)
        {
            first = arr[i];
        }
    }

    int second = -1;
    // second largest element
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] != first)
        {
            if (second == -1 || arr[i] > second)
            {
                second = arr[i];
            }
        }
    }

    // If second is still -1, it means there was no second largest
    return (second == -1) ? -1 : second;
}