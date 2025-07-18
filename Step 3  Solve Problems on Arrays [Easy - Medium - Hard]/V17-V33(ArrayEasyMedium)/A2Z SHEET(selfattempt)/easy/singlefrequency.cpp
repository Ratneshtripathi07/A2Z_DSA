/*
Given an array of nums of n integers. Every integer in the array appears twice except one integer. Find the number that appeared once in the array.


Examples:
Input : nums = [1, 2, 2, 4, 3, 1, 4]

Output : 3

Explanation : The integer 3 has appeared only once.

Input : nums = [5]

Output : 5

Explanation : The integer 5 has appeared only once.
 */

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int unique = 0;
    for (int num : nums)
    {
        unique ^= num; // XOR property: a ^ a = 0 and a ^ 0 = a
    }
    return unique;
}