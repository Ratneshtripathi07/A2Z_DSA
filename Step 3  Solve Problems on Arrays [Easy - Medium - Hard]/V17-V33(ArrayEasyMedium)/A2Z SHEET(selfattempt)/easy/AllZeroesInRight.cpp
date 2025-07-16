#include <bits/stdc++.h>
using namespace std;

void moveZerosToRight(int arr[], int n)
{
    int cnt = 0; // from the right it reduces the iteration to non zeroes only.

    for (int i = 0; i < n - cnt;)
    {
        if (arr[i] == 0)
        {
            cnt++;

            // Shift all elements from i+1 to end to the left by 1
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            // Place 0 at the end
            arr[n - 1] = 0;

            // DO NOT increment i — check same index again
        }
        else
        {
            i++; // Safe to move on
        }
    }
}

// 0s to the end in place(bfa)
// with O(n²) tc.