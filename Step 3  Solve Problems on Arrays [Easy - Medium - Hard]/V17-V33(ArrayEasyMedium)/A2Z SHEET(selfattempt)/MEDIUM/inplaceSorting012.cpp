/*

Sort an array of 0's 1's and 2's
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
The sorting must be done in-place, without making a copy of the original array.
Examples:
Input: nums = [1, 0, 2, 1, 0]

Output: [0, 0, 1, 1, 2]

Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Input: nums = [0, 0, 1, 1, 1]

Output: [0, 0, 1, 1, 1]

Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos

*/

#include <bits/stdc++.h>
using namespace std;

void sortZeroOneTwo(vector<int> &nums)
{
    // using the frequency hash map:

    int n = nums.size();
    // created a hash array to store the frequency

    // vector<int> freq = {0}; // this declares an array of size 1

    vector<int> freq(3, 0);

    for (int i : nums)
    {
        // freq[nums[i]]++; //written in mistakes copy
        freq[i]++;
    }

    /* // --LEARNING--

    for (auto it = arr.begin(); it != arr.end(); ++it) {
    freq[*it]++;
    }

    or

    for (int num : arr)
        freq[num]++;
    here it's not freq[arr[num]]++; because:
    In the range-based for loop for (int num : arr), num takes on the value of each
    element in arr on each iteration.
    So, num is already the value that you want to use as an index for freq.

    */

    // Fetch and modify the original vector

    for (int i = 0; i < freq.size(); i++)
    {
        // for (int j = 0; j < freq[i]; j++)
        // {
        //     nums[j] = freq[i];
        // } dry run: for i = 0 pass; i=1, j'll start from 0 again-> overwriting the value
        // fix::
        int index = 0;
        for (int j = 0; j < freq[i]; j++)
        {
            nums[index++] = i;
        }
    }
}

// adjacent swapping using two for loops (quick sort algo)

// 3 ptr approach or the dutch national flag approach.
