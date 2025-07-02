/*
    Q. Reverse the array
    Input: 1 2 3 4 5
    Output: 5 4 3 2 1

    Approach:
    1. Brute force method
    2. 2 pointer method
    3. swap() method

    by AI
*/
// bruteforce method
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int temp[n];
    int j = 0;
    // Copy elements in reverse order to temp
    for (int i = n - 1; i >= 0; i--) {
        temp[j++] = arr[i];
    }
    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// 2 pointer method
void reverseArrayTwoPointer(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

// swap() method
void reverseArraySwap(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    reverseArray(arr, n);
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}






