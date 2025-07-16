#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)

{
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
}

int missingnum_2(vector<int> &nums){
    
}