#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// O(1) - Constant Space
void constantSpaceExample(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i; // Only a few variables
    cout << "O(1): Sum from 1 to " << n << " = " << sum << endl;
}

// O(log n) - Logarithmic Space (Recursive Binary Search stack)
bool binarySearchRecursive(vector<int> &arr, int low, int high, int key)
{
    if (low > high)
        return false;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return true;
    if (arr[mid] > key)
        return binarySearchRecursive(arr, low, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}

// O(n) - Linear Space (Storing array or recursion)
int fibonacciLinearSpace(int n)
{
    vector<int> dp(n + 1); // Extra space
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// O(n log n) - Merge Sort auxiliary space
void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
        arr[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    while (i < left.size())
        arr[k++] = left[i++];
    while (j < right.size())
        arr[k++] = right[j++];
}
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// O(n²) - Storing all pairs in 2D array
void quadraticSpaceExample(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "O(n^2): 2D Matrix of size " << n << "x" << n << " created.\n";
}

// O(2^n) - Recursion tree (Fibonacci without memo)
int exponentialSpaceExample(int n)
{
    if (n <= 1)
        return n;
    return exponentialSpaceExample(n - 1) + exponentialSpaceExample(n - 2);
}

// O(n!) - Factorial Space (All permutations stored)
void generatePermutations(vector<int> &nums, vector<bool> &used, vector<int> &temp, vector<vector<int>> &result)
{
    if (temp.size() == nums.size())
    {
        result.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (used[i])
            continue;
        used[i] = true;
        temp.push_back(nums[i]);
        generatePermutations(nums, used, temp, result);
        temp.pop_back();
        used[i] = false;
    }
}
void factorialSpaceExample(int n)
{
    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);
    vector<bool> used(n, false);
    vector<int> temp;
    vector<vector<int>> result;
    generatePermutations(nums, used, temp, result);
    cout << "O(n!): Stored " << result.size() << " permutations.\n";
}

int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};

    constantSpaceExample(n); // O(1)
    cout << "O(log n): Found key? " << binarySearchRecursive(arr, 0, arr.size() - 1, 3) << endl;

    cout << "O(n): Fibonacci(" << n << ") = " << fibonacciLinearSpace(n) << endl;

    vector<int> mergeArr = {4, 3, 2, 1, 5};
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    cout << "O(n log n): Merge sort done with auxiliary arrays.\n";

    quadraticSpaceExample(n); // O(n²)

    cout << "O(2^n): Fibonacci without DP (" << n << ") = " << exponentialSpaceExample(n) << endl;

    factorialSpaceExample(n); // O(n!)

    return 0;
}
