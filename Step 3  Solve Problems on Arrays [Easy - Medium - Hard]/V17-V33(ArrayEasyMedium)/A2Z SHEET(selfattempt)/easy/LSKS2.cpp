// 📍📍the question only demanded the length of the longest subarray
// and not the subarray itself,  but here I have returned the subarray.

#include <bits/stdc++.h>
using namespace std;

/* 

int sum(vector<int> nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return sum;
}

*/

vector<int> LongestSubarrayKSum(int arr[], int n, int k)
{
    // vector<vector<int>> arrayofarrays;
    // arrayofarrays.reserve((n * (n + 1)) / 2);

    // int Longestt[0]= {};
    vector<int> Longest;
    int exist = 0;
    for (int i = 0; i < n; i++)
    {
        // store check return:

        // for (int j = i; j < n; j++)
        // {
        //     vector<int> subarray = {};
        //     int sum = 0;
        //     for (int k = i; k <= j; k++)
        //     {
        //         subarray.push_back(arr[k]);
        //         sum += subarray[k];
        //     }
        for (int j = i; j < n; j++)
        {
            vector<int> subarray = {};
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                subarray.push_back(arr[k]);
                sum += subarray[k];
            }

            if ((sum == k) && subarray.size() > Longest.size())
            {
                // Longest.pop_back();
                // Longest.push_back(subarray);
                exist = 1;
                Longest = subarray;
            }
            // arrayofarrays.push_back(subarray);
        }
    }
    if (exist == 1)
    {
        return Longest;
    }
    else
        return {};

    // fetch
    // int subarrayExists = 0;
    // vector<int> zeroArr = {0};
    // vector<int> longestSubarray = {};
    // for (int i = 0; i < arrayofarrays.size(); i++)
    // {

    //     if (sum(arrayofarrays[i]) == k && arrayofarrays[i].size() > longestSubarray.size())
    //     {
    //         longestSubarray = arrayofarrays[i];
    //         subarrayExists = 1;
    //     }
    //     else
    //         continue;
    // }
    // if (subarrayExists == 1)
    // {
    //     return longestSubarray;
    // }
    // else
    //     return {};
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    vector<int> longestSubarray = LongestSubarrayKSum(arr, n, k);
    for (int i = 0; i < longestSubarray.size(); i++)
    {
        cout << longestSubarray[i] << " ";
    }
}
