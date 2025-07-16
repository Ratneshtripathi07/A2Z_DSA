#include <iostream>  // Required for input/output operations (e.g., std::cout)
#include <vector>    // Required for using std::vector
#include <algorithm> // Not strictly necessary for this approach, but often useful (e.g., std::sort, std::unique)

using namespace std;

/**
 * @brief Finds the union of two sorted integer arrays, ensuring the result is
 * sorted and contains only unique elements.
 *
 * This function implements a two-pointer approach. It iterates through both
 * input arrays simultaneously, comparing elements and adding them to a result
 * vector while handling duplicates efficiently.
 *
 * @param nums1 The first input array (must be sorted in ascending order).
 * @param nums2 The second input array (must be sorted in ascending order).
 * @return A std::vector<int> containing the unique, sorted union of nums1 and nums2.
 */
vector<int> findUnion(const vector<int> &nums1, const vector<int> &nums2)
{
    // Initialize pointers for both input arrays
    int ptr1 = 0; // Pointer for nums1
    int ptr2 = 0; // Pointer for nums2

    // Initialize an empty vector to store the union elements
    vector<int> unionArray;

    // Main loop: Iterate while both pointers are within their respective array bounds
    while (ptr1 < nums1.size() && ptr2 < nums2.size())
    {
        // --- Handle duplicates within nums1 before comparison ---
        // If the current element in nums1 is the same as the previous one (and not the first element),
        // it's a duplicate within nums1. Skip it by advancing ptr1 and continuing to the next iteration.
        if (ptr1 > 0 && nums1[ptr1] == nums1[ptr1 - 1])
        {
            ptr1++;
            continue; // Move to the next iteration without processing nums1[ptr1]
        }

        // --- Handle duplicates within nums2 before comparison ---
        // Similar to nums1, skip duplicates within nums2.
        if (ptr2 > 0 && nums2[ptr2] == nums2[ptr2 - 1])
        {
            ptr2++;
            continue; // Move to the next iteration without processing nums2[ptr2]
        }

        // --- Compare current elements from both arrays ---
        if (nums1[ptr1] < nums2[ptr2])
        {
            // If the element in nums1 is smaller, add it to the unionArray
            unionArray.push_back(nums1[ptr1]);
            ptr1++; // Advance pointer for nums1
        }
        else if (nums2[ptr2] < nums1[ptr1])
        {
            // If the element in nums2 is smaller, add it to the unionArray
            unionArray.push_back(nums2[ptr2]);
            ptr2++; // Advance pointer for nums2
        }
        else
        { // nums1[ptr1] == nums2[ptr2] (elements are equal)
            // If elements are equal, add one of them (doesn't matter which, as they are identical)
            // to the unionArray to ensure it's included only once.
            unionArray.push_back(nums1[ptr1]);
            ptr1++; // Advance pointer for nums1
            ptr2++; // Advance pointer for nums2
        }
    }

    // --- Process remaining elements in nums1 (if any) ---
    // After the main loop, one of the arrays might have elements left.
    // This loop adds any remaining unique elements from nums1 to the unionArray.
    while (ptr1 < nums1.size())
    {
        // Handle duplicates within the remaining part of nums1
        if (ptr1 > 0 && nums1[ptr1] == nums1[ptr1 - 1])
        {
            ptr1++;
            continue;
        }
        unionArray.push_back(nums1[ptr1]);
        ptr1++;
    }

    // --- Process remaining elements in nums2 (if any) ---
    // This loop adds any remaining unique elements from nums2 to the unionArray.
    while (ptr2 < nums2.size())
    {
        // Handle duplicates within the remaining part of nums2
        if (ptr2 > 0 && nums2[ptr2] == nums2[ptr2 - 1])
        {
            ptr2++;
            continue;
        }
        unionArray.push_back(nums2[ptr2]);
        ptr2++;
    }

    // Return the final union array
    return unionArray;
}

// Helper function to print a vector
void printVector(const vector<int> &arr, const string &name)
{
    cout << name << ": [";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Main function to test the findUnion function
int main()
{
    // Test Case 1: Standard case with duplicates in both arrays and common elements
    vector<int> nums1_1 = {1, 2, 2, 3, 4, 5};
    vector<int> nums2_1 = {2, 3, 3, 5, 6, 7};
    printVector(nums1_1, "nums1_1");
    printVector(nums2_1, "nums2_1");
    vector<int> union1 = findUnion(nums1_1, nums2_1);
    printVector(union1, "Union 1"); // Expected: [1, 2, 3, 4, 5, 6, 7]
    cout << endl;

    // Test Case 2: One array exhausted first, with remaining duplicates in the other
    vector<int> nums1_2 = {1, 1, 2, 3, 3, 4, 4, 5};
    vector<int> nums2_2 = {2, 5};
    printVector(nums1_2, "nums1_2");
    printVector(nums2_2, "nums2_2");
    vector<int> union2 = findUnion(nums1_2, nums2_2);
    printVector(union2, "Union 2"); // Expected: [1, 2, 3, 4, 5]
    cout << endl;

    // Test Case 3: Empty array
    vector<int> nums1_3 = {10, 20, 30};
    vector<int> nums2_3 = {};
    printVector(nums1_3, "nums1_3");
    printVector(nums2_3, "nums2_3");
    vector<int> union3 = findUnion(nums1_3, nums2_3);
    printVector(union3, "Union 3"); // Expected: [10, 20, 30]
    cout << endl;

    // Test Case 4: Both arrays empty
    vector<int> nums1_4 = {};
    vector<int> nums2_4 = {};
    printVector(nums1_4, "nums1_4");
    printVector(nums2_4, "nums2_4");
    vector<int> union4 = findUnion(nums1_4, nums2_4);
    printVector(union4, "Union 4"); // Expected: []
    cout << endl;

    // Test Case 5: All elements common and duplicated
    vector<int> nums1_5 = {1, 1, 1, 2, 2};
    vector<int> nums2_5 = {1, 2, 2, 2};
    printVector(nums1_5, "nums1_5");
    printVector(nums2_5, "nums2_5");
    vector<int> union5 = findUnion(nums1_5, nums2_5);
    printVector(union5, "Union 5"); // Expected: [1, 2]
    cout << endl;

    return 0; // Indicate successful execution
}

// normal STL Function use code (no self algorithm)

void arrayUnion_using_STL(vector<int> &arr1, vector<int> &arr2)
{

    // ai code

    vector<int> unionArr;

    // Merge the two arrays

    // unionArr.reserve(arr1.size() + arr2.size());
    // Reserve ka matlab hota hai ki hum pehle se hi vector ke andar itni jagah allocate kar lete hain
    // jitni humein chahiye, taki jab hum elements insert karein to baar-baar memory reallocate na ho.
    // Yahan pe hum arr1 aur arr2 dono ki size ka total le rahe hain,
    // aur utni space unionArr vector ke liye reserve kar rahe hain.
    unionArr.reserve(arr1.size() + arr2.size());

    // Yahan pe hum arr1 ke saare elements ko unionArr ke end me daal rahe hain.
    // insert function ka matlab hai: unionArr ke end me, arr1 ke starting se lekar end tak ke elements daal do.

    unionArr.insert(unionArr.end(), arr1.begin(), arr1.end()); // If you want to use push_back, you would need a loop
    unionArr.insert(unionArr.end(), arr2.begin(), arr2.end());

    // Sort the merged array
    sort(unionArr.begin(), unionArr.end());

    // Remove duplicates
    // unique() function kya karta hai? Ye sorted array me se consecutive duplicate elements hata
    // deta hai,
    // aur ek iterator return karta hai jo last unique element ke baad ka position batata hai.
    auto last = unique(unionArr.begin(), unionArr.end());
    unionArr.erase(last, unionArr.end());
}
