#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// bruteforce Algorithm
int gcd(int a, int b)
{
    // container for divisors
    vector<int> div1, div2;

    // adding divisors - start from 1 to avoid division by zero
    for (int i = 1; i <= a; ++i)
    {
        if (a % i == 0)
        {
            div1.push_back(i);
        }
    }
    for (int i = 1; i <= b; ++i)
    {
        if (b % i == 0)
        {
            div2.push_back(i);
        }
    }

    // find common divisors
    vector<int> common;
    for (int i = 0; i < div1.size(); ++i)
    {
        for (int j = 0; j < div2.size(); ++j)
        {
            if (div1[i] == div2[j])
            {
                common.push_back(div1[i]);
            }
        }
    }

    // greatest in the common vector
    int result = *max_element(common.begin(), common.end());
    return result;
}

// m-2 euclidean algorithm

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << gcd(a, b); // Use the input variables instead of hardcoded values

    return 0;
}