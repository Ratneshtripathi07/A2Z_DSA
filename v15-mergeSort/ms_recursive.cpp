#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Merges two sorted sub-arrays into a single sorted sub-array.
 * @param arr The main vector containing the data.
 * @param left The starting index of the first sub-array.
 * @param mid The ending index of the first sub-array.
 * @param right The ending index of the second sub-array.
 */

// Merge Logic


void merge(vector<int> &arr, int left, int mid, int right)
{
    // Calculate the sizes of the two temporary sub-arrays
    int size1 = mid - left + 1;
    int size2 = right - mid;

    // Create temporary vectors to hold the sub-array data
    vector<int> leftArr(size1);
    vector<int> rightArr(size2);

    // Copy data from the main vector to the temporary sub-arrays
    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < size2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Initialize pointers for the two temporary arrays and the main array
    int i = 0;    // Initial index for the left sub-array
    int j = 0;    // Initial index for the right sub-array
    int k = left; // Initial index for the merged sub-array in the main vector

    // Compare elements from both sub-arrays and merge them in sorted order
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

    // If there are any remaining elements in the left sub-array, copy them
    while (i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // If there are any remaining elements in the right sub-array, copy them
    while (j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/**
 * @brief The main recursive function that sorts the vector using the Merge Sort algorithm.
 * @param arr The vector to be sorted.
 * @param begin The starting index of the segment to sort.
 * @param end The ending index of the segment to sort.
 */
void mergeSort(vector<int> &arr, int begin, int end)
{
    // Base case: if the segment has 0 or 1 elements, it is already sorted.
    if (begin >= end)
    {
        return;
    }

    // Find the middle point to divide the array.
    int mid = begin + (end - begin) / 2;

    // Recursively sort the first half.
    mergeSort(arr, begin, mid);

    // Recursively sort the second half.
    mergeSort(arr, mid + 1, end);

    // Merge the two sorted halves.
    merge(arr, begin, mid, end);
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
    // Example array from the candidate's notes
    vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6};

    cout << "Original array: ";
    printArray(arr);

    // Call mergeSort on the entire array
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}