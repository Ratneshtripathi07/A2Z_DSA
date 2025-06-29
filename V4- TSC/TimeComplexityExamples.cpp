#include <iostream>
#include <vector>
using namespace std;

// O(1) - Constant Time
void constantTimeExample()
{
    int x = 42;
    cout << "O(1): Constant value: " << x << endl;
}

// O(log n) - Logarithmic Time (Binary Search)
void logTimeExample(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            cout << "O(log n): Found key!" << endl;
            return;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "O(log n): Key not found." << endl;
}

// O(n) - Linear Time
void linearTimeExample(vector<int> &arr)
{
    int sum = 0;
    for (int num : arr)
        sum += num;
    cout << "O(n): Sum = " << sum << endl;
}

// O(n log n) - Linearithmic Time (Merge Sort)
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
void nLognTimeExample(vector<int> &arr)
{
    mergeSort(arr, 0, arr.size() - 1);
    cout << "O(n log n): Sorted array using merge sort.\n";
}

// O(n^2) - Quadratic Time (Bubble Sort)
void quadraticTimeExample(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    cout << "O(n^2): Sorted using bubble sort.\n";
}

// O(n^3) - Cubic Time (3-nested loops)
void cubicTimeExample(int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                ++count;
    cout << "O(n^3): Triple loop count = " << count << endl;
}

// O(2^n) - Exponential Time (Fibonacci)
int exponentialTimeExample(int n)
{
    if (n <= 1)
        return n;
    return exponentialTimeExample(n - 1) + exponentialTimeExample(n - 2);
}

// O(n!) - Factorial Time (Permutations)
int factorialTimeExample(int n)
{
    if (n == 0)
        return 1;
    return n * factorialTimeExample(n - 1);
}

int main()
{
    int n = 5;
    vector<int> arr = {5, 3, 8, 6, 2};

    constantTimeExample();
    logTimeExample(arr, 6);
    linearTimeExample(arr);
    nLognTimeExample(arr);
    quadraticTimeExample(arr);
    cubicTimeExample(n);

    cout << "O(2^n): Fibonacci(" << n << ") = " << exponentialTimeExample(n) << endl;
    cout << "O(n!): Factorial(" << n << ") = " << factorialTimeExample(n) << endl;

    return 0;
}
