#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min

// Use the standard namespace
using namespace std;

/**
 * @brief Merges two sorted sub-arrays into a single sorted sub-array.
 * This function is identical to the one used in the recursive version.
 * @param arr The main vector containing the data.
 * @param left The starting index of the first sub-array.
 * @param mid The ending index of the first sub-array.
 * @param right The ending index of the second sub-array.
 */

// Merge Logic

void merge(vector<int> &arr, int left, int mid, int right)
{
    // Calculate sizes of the two sub-arrays to be merged
    int size1 = mid - left + 1;
    int size2 = right - mid;

    // Create temporary vectors
    vector<int> leftArr(size1);
    vector<int> rightArr(size2);

    // Copy data to temporary vectors
    for (int i = 0; i < size1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < size2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary vectors back into the original array
    int i = 0;    // Initial index of first sub-array
    int j = 0;    // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while (i < size1 && j < size2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArr[]
    while (i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArr[]
    while (j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/**
 * @brief Sorts a vector using the iterative (bottom-up) Merge Sort algorithm.
 * @param arr The vector to be sorted.
 */

//

void mergeSortIterative(vector<int> &arr)
{
    int n = arr.size();

    // The outer loop sets the size of the sub-arrays to be merged.
    // It starts with sub-arrays of size 1, then 2, 4, 8, and so on.
    for (int current_size = 1; current_size < n; current_size = 2 * current_size)
    {

        // The inner loop picks the starting point of the left sub-array for merging.
        // It iterates through the array, processing pairs of sub-arrays.
        for (int left_start = 0; left_start < n; left_start += 2 * current_size)
        {

            // Determine the mid and end points for the merge operation.
            // Using std::min ensures we don't go out of bounds.
            int mid = min(left_start + current_size - 1, n - 1);
            int right_end = min(left_start + 2 * current_size - 1, n - 1);

            // Call merge for the pair of sub-arrays arr[left_start...mid]
            // and arr[mid+1...right_end]. The check 'mid < right_end' is an
            // implicit optimization as merge would do nothing if there's no right part.
            if (mid < right_end)
            {
                merge(arr, left_start, mid, right_end);
            }
        }
    }
}

/**
 * @brief A helper function to print the elements of a vector.
 * @param arr The vector to be printed.
 */
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to drive the program
int main()
{
    vector<int> arr = {3, 1, 2, 4, 5, 2, 6, 7, 3, 1, 6, 5, 8, 3, 5, 7, 8, 9};

    cout << "Original array: ";
    printArray(arr);

    // Call the iterative mergeSort function
    mergeSortIterative(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}