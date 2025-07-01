#include <iostream>
#include <vector>
using namespace std;

// 1️⃣ Factorial (basic recursion)
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// 2️⃣ Fibonacci (multiple recursion)
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3️⃣ Print numbers from N to 1 (backtracking-style)
void printNto1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printNto1(n - 1);
}

// 4️⃣ Sum of digits
int sumOfDigits(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumOfDigits(n / 10);
}

// 5️⃣ Reverse a string using recursion
void reverseString(string &s, int i, int j)
{
    if (i >= j)
        return;
    swap(s[i], s[j]);
    reverseString(s, i + 1, j - 1);
}

// 6️⃣ Check if array is sorted
bool isSorted(vector<int> &arr, int idx)
{
    if (idx == arr.size() - 1)
        return true;
    return arr[idx] <= arr[idx + 1] && isSorted(arr, idx + 1);
}

// 7️⃣ Power using recursion (a^b)
int power(int a, int b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

// 8️⃣ Binary Search using recursion
int binarySearch(vector<int> &arr, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}

// DRIVER CODE
int main()
{
    cout << "Factorial(5): " << factorial(5) << endl;

    cout << "Fibonacci(6): " << fibonacci(6) << endl;

    cout << "Print N to 1: ";
    printNto1(5);
    cout << endl;

    cout << "Sum of digits (1234): " << sumOfDigits(1234) << endl;

    string str = "hello";
    reverseString(str, 0, str.size() - 1);
    cout << "Reversed string: " << str << endl;

    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Is array sorted? " << (isSorted(arr, 0) ? "Yes" : "No") << endl;

    cout << "2^5 using power: " << power(2, 5) << endl;

    vector<int> sortedArr = {1, 3, 5, 7, 9, 11};
    int index = binarySearch(sortedArr, 0, sortedArr.size() - 1, 7);
    cout << "Index of 7 in sorted array: " << index << endl;

    return 0;
}
