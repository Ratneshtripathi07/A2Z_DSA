/*

Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. 
If no such sub-array exists, return 0.

Examples:

Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. 
This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. 
Therefore, the length of this sub-array is 4.

Input: nums = [-3, 2, 1], k=6
Output: 0
Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.

*/

#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return sum;
}

vector<int> LongestSubarrayKSum(int arr[], int n, int k)
{
    vector<vector<int>> arrayofarrays;
    arrayofarrays.reserve((n * (n + 1)) / 2);
    // for (int i = 0; i < n; i++)
    // {
    //     // store

    //     for (int j = 0; j < n; j++)
    //     {
    //         //// arrayofarrays.push_back(vector<int> nums(j));
    //         //// for (int k = 0; k < nums.size(); k++)
    //         vector<int> subarray = {};
    //         for (int k = 0; k <= j; k++)

    //         {
    //             subarray.push_back(arr[k]);
    //         }
    //         arrayofarrays.push_back(subarray);
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        // store

        for (int j = i; j < n; j++) // update: j=i
        {
            //// arrayofarrays.push_back(vector<int> nums(j));
            //// for (int k = 0; k < nums.size(); k++)
            vector<int> subarray = {};
            for (int k = i; k <= j; k++) // update: k=i

            {
                subarray.push_back(arr[k]);
            }
            arrayofarrays.push_back(subarray);
        }
    }

    // fetch
    int subarrayExists = 0;
    vector<int> zeroArr = {0};
    vector<int> longestSubarray = {};
    for (int i = 0; i < arrayofarrays.size(); i++)
    {

        if (sum(arrayofarrays[i]) == k && arrayofarrays[i].size() > longestSubarray.size())
        {
            longestSubarray = arrayofarrays[i];
            subarrayExists = 1;
        }
        else
            continue;
    }
    if (subarrayExists == 1)
    {
        return longestSubarray;
    }
    else
        return {};
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    vector<int> longestSubarray = LongestSubarrayKSum(arr, n, k);
    for (int i = 0; i < longestSubarray.size(); i++)
    {
        cout << longestSubarray[i] << " ";
    }
}