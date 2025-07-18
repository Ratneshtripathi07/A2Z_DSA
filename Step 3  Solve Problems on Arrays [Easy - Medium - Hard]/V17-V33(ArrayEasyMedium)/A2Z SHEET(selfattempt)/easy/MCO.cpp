#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0;
    int temp = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            // temp = cnt;
            temp = max(temp, cnt); // to handle the case where the vector ends with '1's
            cnt = 0;
        }
    }

    // return temp;
    return max(temp, cnt);
}

int main()
{

    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0};

    cout << "MCOs: " << findMaxConsecutiveOnes(nums) << endl;
}

// code had a small error in how it calculates the maximum consecutive ones. The temp variable is updated only when a '0' is encountered,
// and the final count of consecutive ones might not be stored in temp if the vector // ends with '1's.