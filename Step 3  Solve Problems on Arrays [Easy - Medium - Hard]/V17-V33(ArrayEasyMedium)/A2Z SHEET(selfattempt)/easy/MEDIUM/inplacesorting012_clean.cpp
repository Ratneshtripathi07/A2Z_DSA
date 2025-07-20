#include <bits/stdc++.h>
using namespace std;

void sortZeroOneTwo(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(3, 0); //

    for (int i : nums)
        freq[i]++;

    int index = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        for (int j = 0; j < freq[i]; j++)
        {
            nums[index++] = i; //
        }
    }
}
int main()
{
    vector<int> nums1 = {1, 0, 2, 1, 0};
    cout << "Input: nums = [1, 0, 2, 1, 0]" << endl;
    cout << "Before sorting: ";
    for (int num : nums1)
        cout << num << " ";
    cout << endl;
    
    sortZeroOneTwo(nums1);
    
    cout << "After sorting: ";
    for (int num : nums1)
        cout << num << " ";
    cout << endl;
    
    cout << endl;
    
    vector<int> nums2 = {0, 0, 1, 1, 1};
    cout << "Input: nums = [0, 0, 1, 1, 1]" << endl;
    cout << "Before sorting: ";
    for (int num : nums2)
        cout << num << " ";
    cout << endl;
    
    sortZeroOneTwo(nums2);
    
    cout << "After sorting: ";
    for (int num : nums2)
        cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
Time Complexity Analysis:
- First loop (counting frequencies): O(n) where n is the size of the array
- Second loop (reconstructing array): O(n) in total across all iterations
  - The inner loop runs freq[i] times for each i (0, 1, 2)
  - Total iterations = freq[0] + freq[1] + freq[2] = n
- Overall Time Complexity: O(n) + O(n) = O(n)

Space Complexity Analysis:
- freq vector: O(1) since it's always size 3 regardless of input size
- No additional data structures that grow with input size
- Overall Space Complexity: O(1)

This is an efficient approach for sorting arrays with only 0s, 1s, and 2s.
*/