#include <bits/stdc++.h>
using namespace std;

vector<int> LongestSubarrayKSum(int arr[], int n, int k)
{
    vector<int> Longest;
    int exist = 0;
    for (int i = 0; i < n; i++)
    {

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

                exist = 1;
                Longest = subarray; //subarray updated with the 
            }
        }
    }
    if (exist == 1)
    {
        return Longest;
    }
    else
        return {};

}

int main()
{
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    vector<int> longestSubarray = LongestSubarrayKSum(arr, n, k);
    for (int i = 0; i < longestSubarray.size(); i++)
    {
        cout << longestSubarray[i] << " ";
    }
}
// -----------------------------------------------------------------------

// better bruteforce:

vector<int> LongestSubarrayKSum2(int arr[], int n, int k)
{
    vector<int> Longest;
    int exist = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            // write code here..
            
        }
    }
    if (exist == 1)
    {
        return Longest;
    }
    else
        return {};
}

// reference code

/*
vector<int> LongestSubarrayKSum(int arr[], int n, int k)
{
    vector<int> Longest;
    int exist = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k && j - i + 1 > Longest.size())
            {
                exist = 1;
                Longest = vector<int>(arr + i, arr + j + 1);
            }
        }
    }
    if (exist == 1)
    {
        return Longest;
    }
    else
        return {};
}
*/