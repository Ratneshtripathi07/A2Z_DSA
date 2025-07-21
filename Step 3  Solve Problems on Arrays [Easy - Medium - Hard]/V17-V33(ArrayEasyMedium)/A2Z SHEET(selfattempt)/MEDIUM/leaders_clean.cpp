#include <bits/stdc++.h>
using namespace std;


// my initial implementation's refactored version

vector<int> leaders(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nums2;

    // Handle edge cases
    if (n == 0)
        return nums2;
    if (n == 1)
    {
        nums2.push_back(nums[0]);
        return nums2;
    }

    int p1 = 0, p2 = n - 1;
    int cnt = 0;

    while (p1 < n - 1) // Check until p1 reaches second-to-last element
    {
        int x = nums[p1], y = nums[p2];
        if (y > x) // If right element is larger, nums[p1] is not a leader
        {
            p1++;       // Move to next element
            p2 = n - 1; // Reset p2
            cnt = 0;    // Reset count for new p1
        }
        else // x >= y
        {
            p2--;         // Compare with next element to the left
            cnt++;        // Increment count of elements nums[p1] is greater than
            if (p2 == p1) // If we've checked all elements to the right
            {
                //📍 if(p2==p1) can be removed cuz if (cnt == n - p1 - 1) itself is a check.
                if (cnt == n - p1 - 1) // true if nums[p1] is greater than all elements to its right
                {
                    nums2.push_back(nums[p1]);
                }
                p1++;       // Move to next element
                p2 = n - 1; // Reset p2
                cnt = 0;    // Reset count
            }
        }
    }

    nums2.push_back(nums[n - 1]); // Last element is always a leader
    return nums2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> nums;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> result = leaders(nums);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
