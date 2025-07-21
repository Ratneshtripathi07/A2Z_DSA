#include <bits/stdc++.h>
using namespace std;

/*

// my initial implementation (bf logic is ✅) 

vector<int> leaders(vector<int> &nums)
{
    int n = nums.size();
    int p1 = 0, p2 = n - 1;
    // int p2 = n-1;
    vector<int> nums2;
    int x = nums[p1], y = nums[p2];

    while (p2 > p1 && p1 < n - 1)
    {
        int cnt = 0;
        if (y > x)
        {
            p1++;
            p2 = n - 1;
        }
        else if (x >= y)
        {
            p2--;
            cnt++;
            if (cnt == ((p2 - p1) - 1))
            {
                nums2.push_back(nums[p1]);
                
            }
        }
    }
    nums2.push_back(nums[n - 1]);
    return nums2;
}

*/

// other implementations

vector<int> leaders1(vector<int> &arr)
{
    int n = arr.size();
    vector<int> leaders;
    int p1 = 0;

    while (p1 < n - 1)
    {
        int p2 = n - 1;
        bool isLeader = true;

        while (p2 > p1)
        {
            if (arr[p2] > arr[p1])
            {
                isLeader = false;
                break;
            }
            p2--;
        }

        if (isLeader)
            leaders.push_back(arr[p1]);

        p1++;
    }

    leaders.push_back(arr[n - 1]); // Last element is always a leader
    return leaders;
}

vector<int> leaders2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result;
    int p1 = 0;

    while (p1 < n - 1)
    {
        int p2 = p1 + 1;
        bool isLeader = true;

        while (p2 < n)
        {
            if (nums[p2] > nums[p1])
            {
                isLeader = false;
                break;
            }
            p2++;
        }

        if (isLeader)
        {
            result.push_back(nums[p1]);
        }
        p1++;
    }

    result.push_back(nums[n - 1]);
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> nums;
    for (int i = 0; i < 5; i++) // -1 -2 -3 -4 -5

    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> result = leaders1(nums); //or leaders2

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl; // -1 -2 -3 -4 -5

    return 0;
}
