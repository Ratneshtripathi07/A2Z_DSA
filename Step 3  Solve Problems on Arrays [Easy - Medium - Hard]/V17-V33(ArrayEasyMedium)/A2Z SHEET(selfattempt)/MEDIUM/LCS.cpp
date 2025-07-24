/*

Given an array nums of n integers, return the length of the longest sequence of consecutive integers.
The integers in this sequence can appear in any order.


Examples:
Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4.
This sequence can be formed regardless of the initial order of the elements in the array.

Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Output: 9

Explanation: The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length
of 9.

Constraints:
     1 <= nums.length <= 105
     -109 <= num <= 109

*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    // Attempt 1st
    // int n = nums.size();
    // // edge case
    // if (n == 1)
    // {
    //     return n;
    // }

    // //
    // int LCO = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int cnt = 0;
    //     int LCOinitNum;
    //     for (int j = 1; j < n; j++)
    //     {
    //         int num = nums[i];
    //         int cc = 1; // consecutive count
    //         // If no consecutive integer, we should continue to the next i (outer loop), so break is correct here.
    //         if ((j != i && nums[j] != num + cc) || (j != i && nums[j] != num - cc))
    //         {
    //             continue;
    //         }
    //         if (num == num + j)
    //         {
    //             cnt++;
    //             LCOinitNum = i;
    //         }
    //         else if (j < i && num == num - j)
    //         {
    //             cnt++;
    //             LCOinitNum = i - j;
    //         }
    //     }
    // }
}

int longestConsecutive2(vector<int> &nums)
{
    // Attempt 2nd
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Step 1: Sort the array
    int cnt = 1;                    // Start with 1 (a single number is a sequence of length 1)
    int LCS = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            continue; // Skip duplicates: it skips the rest of the current iteration and moves on to next.

        if (nums[i] == nums[i - 1] + 1)
        {
            cnt++; // Consecutive
        }
        else
        {
            cnt = 1; // Reset if break in sequence
        }

        LCS = max(LCS, cnt); // Track maximum
    }
}

int longestConsecutive3(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int cnt = 1;
    int LCS = 1;
    for (int i = 0; i < n; i++)
    {
        // duplicates
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        // rest

        if (nums[i] == nums[i - 1] + 1)
        {
            cnt++; // Consecutive
            if (cnt > LCS)
            {
                LCS = cnt;
            }
        }
        else
        {
            cnt = 1;
        }
    }
    return LCS;
}

int longestConsecutive4(vector<int> &nums)
{
    int n = nums.size();
    // Handle the edge case of an empty array
    if (n == 0)
    {
        return 0;
    }

    // Sort the array to easily find consecutive elements
    sort(nums.begin(), nums.end());

    int cnt = 1; // Current consecutive count
    int LCS = 1; // Longest consecutive sequence found so far

    // Iterate from the second element (index 1) to compare with the previous one
    for (int i = 1; i < n; i++)
    {
        // If the current number is a duplicate of the previous one, skip it.
        // The current consecutive sequence length (cnt) remains unchanged.
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        // If the current number is exactly one greater than the previous number,
        // it's part of the current consecutive sequence.
        else if (nums[i] == nums[i - 1] + 1)
        {
            cnt++; // Increment the current consecutive count
        }
        // If the current number is not consecutive and not a duplicate,
        // it means the current consecutive sequence has ended.
        // Reset cnt to 1, as the current number starts a new potential sequence.
        else
        {
            cnt = 1;
        }

        // After updating cnt for the current iteration,
        // check if it's greater than the overall longest consecutive sequence found so far.
        // If it is, update LCS.
        if (cnt > LCS)
        {
            LCS = cnt;
        }
    }
    return LCS; // Return the maximum length found
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    /*

    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int result = longestConsecutive3(nums);
    cout << result << endl;

    */
}