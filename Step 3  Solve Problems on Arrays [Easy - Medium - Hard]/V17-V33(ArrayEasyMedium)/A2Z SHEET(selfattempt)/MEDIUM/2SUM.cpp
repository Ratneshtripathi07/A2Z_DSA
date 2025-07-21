/*
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements
in nums such that they add up to target.
Each input will have exactly one solution, and the same element cannot be used twice.
Return the answer in non-decreasing order.
Examples:
Input: nums = [1, 6, 2, 10, 3], target = 7
Output: [0, 1]
Explanation: nums[0] + nums[1] = 1 + 6 = 7
Input: nums = [1, 3, 5, -7, 6, -3], target = 0
Output: [1, 5]
Explanation: nums[1] + nums[5] = 3 + (-3) = 0
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    // bfa
    vector<int> oparr;
    for (int i = 0; i < n; i++)
    {
        //for (int j = 0; j < n; j++) // Output: [1,1,5,5]
        /*
        for
        Input: nums = [1, 6, 2, 10, 3], target = 7-

        When i was 1 and j was 5, the condition nums[i] + nums[j] == target was true,
        so the indices 1 and 5 were added to oparr. However, when i was 5 and j was 1,
        the condition was true again
        */
        for (int j = i+1; j < n; j++) //compare i with the number just after it
        {
            if (nums[i] + nums[j] == target)
            {
                oparr.push_back(i);
                oparr.push_back(j);
                sort(oparr.begin(), oparr.end());
            }
        }
    }
    return oparr;
}

int main()
{
    vector<int> nums1 = {1, 6, 2, 10, 3};
    int target1 = 7;
    vector<int> result1 = twoSum(nums1, target1);
    cout << "Input: nums = [1, 6, 2, 10, 3], target = 7" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i];
        if (i < result1.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;

    return 0;
}


// better / optimal solutin using the hashmaps:

