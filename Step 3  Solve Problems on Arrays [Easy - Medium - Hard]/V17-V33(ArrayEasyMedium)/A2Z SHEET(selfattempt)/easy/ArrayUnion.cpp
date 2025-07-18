//  n1 and n2 are sorted arrays
//  bfa - a dynamic new arr n3 with all the from n1 and the uncommon from n2. (p.s: it's not bfa rather better and close to optimal)
//  sort the new array.
#include <bits/stdc++.h>
using namespace std;

// int arrayUnion(vector<int> &nums1, vector<int> &nums2) // vector data type is being returned, not normal int
vector<int> arrayUnion(vector<int> &nums1, vector<int> &nums2)
{
    // vector<int> union; union is some STL function
    vector<int> union1; // union array

    // two pointer method

    int ptr1 = 0;
    int ptr2 = 0;

    // for sake of simplicity, can be avoided // it being outside main loop causes no updation
    // int x = nums1[ptr1];
    // int y = nums2[ptr2];
    // main loop

    while (ptr1 < nums1.size() && ptr2 < nums2.size())
    {
        // here it's fine.
        int x = nums1[ptr1];
        int y = nums2[ptr2];
        /*

        check- dono arrays me ptr duplicate pe nhi hai
        if ( x != nums1[ptr1 + 1] &&  y != nums2[ptr2 + 1]) // doesn't handle out of bound
        if (ptr1< nums1.size()-2 && x != nums1[ptr1 + 1] && ptr2 < nums2.size()-2 && y != nums2[ptr2 + 1])

        ptr1 + 1 < nums1.size() handles out of bound

        || ka matlab hota hai: agar dono me se koi ek condition true ho gayi, toh poora condition true maan lo.

        why ptr1 + 1 < nums1.size() || x != nums1[ptr1 + 1] is incorrect
        ptr1 +1 < nums1.size() most of the time correct hai.

        if ((ptr1 + 1 < nums1.size() || x != nums1[ptr1 + 1]) && (ptr2 + 1 < nums2.size() || y != nums2[ptr2 + 1]))

        */

        if ((ptr1 + 1 >= nums1.size() || x != nums1[ptr1 + 1]) &&
            (ptr2 + 1 >= nums2.size() || y != nums2[ptr2 + 1])) // is correct bcuz:
        /*

        Agar array ke end me ho, jaise ptr1 == nums1.size() - 1
        Toh ptr1 + 1 == nums1.size() → out of bounds hoga.
        Isliye,
        agar next element exist nahi karta, toh hum bas assume kar lete hain ki duplicate nahi hai.

         */
        {
            if (x < y)
            {
                union1.push_back(x);
                ptr1++;
            }
            else if (y < x)
            {
                union1.push_back(y);
                ptr2++;
            }
            // else if (x == y)
            else
            {
                union1.push_back(x);
                ptr1++;
                ptr2++;
            }
        }
        // duplicates handling within arrays
        else if (x == nums1[ptr1 + 1])
        {
            ptr1++;
        }
        else if (y == nums2[ptr2 + 1])
        {
            ptr2++;
        }
    }
    // one of the arrays exceed the bounds and loop breaks

    // if it was the first array
    while (ptr1 < nums1.size())
    {
        int x = nums1[ptr1];
        // duplicates check
        if (x == nums1[ptr1 + 1])
        {
            ptr1++;
        }
        else
            union1.push_back(nums1[ptr1]);
        //
        ptr1++;
    }
    while (ptr2 < nums2.size())
    {
        int y = nums2[ptr2];
        // duplicates check
        if (y == nums2[ptr2 + 1])
        {
            ptr2++;
        }
        else
            union1.push_back(nums2[ptr2]);
        //
        ptr2++;
    }

    // return Union1 array

    return union1;
}

int main()
{
    vector<int> a = {1, 2, 2, 4, 5, 5};
    vector<int> b = {2, 3, 5, 6};

    vector<int> res = arrayUnion(a, b);
    for (int num : res)
        cout << num << " ";
}

// P.S. :
/*
Approach Summary:
1. Initialize two pointers: Set two pointers, ptr1 and ptr2, to the start of the two input arrays nums1 and nums2, respectively.
2. Compare elements: Compare the elements at the current positions of ptr1 and ptr2.
3. Check for duplicates: Before adding an element to the union array, check if it's not a duplicate in its respective array by comparing
   it with the next element. If the next element is out of bounds, assume it's not a duplicate.
4. Add smaller element: Add the smaller element to the union array and increment the corresponding pointer. If both elements are equal,
   add one of them to the union array and increment both pointers.
5. Handle duplicates: If an element is a duplicate in its array, increment the pointer without adding it to the union array.
6. Handle remaining elements: Once one of the arrays is exhausted, add the remaining elements from the other array to the union array,
   skipping duplicates.
7. Return the union array: Return the resulting union array containing unique elements from both input arrays.
The approach uses a two-pointer technique to efficiently merge the two sorted arrays and remove duplicates.
*/

// it's not BF but the optimal solution, congrats.