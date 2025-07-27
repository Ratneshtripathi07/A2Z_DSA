/*

Best time to buy and sell stock

Given an array arr of n integers, where arr[i] represents price of the stock on the ith day.
Determine the maximum profit achievable by buying and selling the stock at most once.
The stock should be purchased before selling it, and both actions cannot occur on the same day.

Examples:
Input: arr = [10, 7, 5, 8, 11, 9]
Output: 6
Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.

Input: arr = [5, 4, 3, 2, 1]
Output: 0
Explanation: In this case, no transactions are made. Therefore, the maximum profit remains 0.

Constraints:
1 <= n<= 105
0 <= arr[i] <= 106


*/

#include <bits/stdc++.h>
using namespace std;

int stockBuySell_1(vector<int> arr, int n)
{
    // max and min elem
    // if indexOfMax > indexOfMin
    // return arr[max]-arr[min]
    // else return 0;
    int max, min = arr[0];
    int imax, imin;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            imax = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            imin = i;
        }
    }

    if (imax > imin)
    {
        return max - min;
    }
    else
        return 0;
}

// only returns for max elements
// failing case maybe: 11,2,3,3,4,5,1
// qs: Determine the maximum profit 'achievable'. here it is 5-2 = 3

// so new approach // pr = profit inside loop , mpr = maxProfit ouside loop
// bfa: for every element traverse the next elements, if greater update profit and mpr(IF pr > mpr)
// 9,2,11,3,4,1,5,6,7,10

int stockBuySell_bf(vector<int> arr, int n)
{
    // bfa
    if (n == 1)
    {
        return 0;
    }
    int mpr = 0; // maxPROFIT
    int profited = 0;
    for (int i = 0; i < n - 1; i++) // cuz if bought last day, can't be sold
    {
        int pr = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                pr = arr[j] - arr[i];
                if (pr > mpr)
                {
                    mpr = pr;
                    profited = 1;
                }
            }
        }
    }
    if (profited == 1)
    {
        return mpr;
    }
    else
        return 0;
}

int stockBuySell_bt(vector<int> arr, int n)
{

}
