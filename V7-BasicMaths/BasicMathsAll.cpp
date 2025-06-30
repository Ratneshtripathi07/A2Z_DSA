#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int DigitExtraction(int n)
{
    int digits = 0;
    // for (int i = n; i > 0; i / 10) // endless loop
    for (int i = n; i > 0; i /= 10)
    {
        digits += 1;
    }
    return digits;
    // cout << digits;
}

void revnum_clean(int n)
{
    // remainder * 10 raised to power (digit - 1) logic
    int revnumm = 0;

    // Remove trailing zeroes
    while (n % 10 == 0 && n > 0)
    {
        n /= 10;
    }

    // Count digits after removing trailing zeroes
    int digitss = DigitExtraction(n);

    // Construct reversed number
    for (int j = n; j > 0; j /= 10, digitss--)
    {
        int remainder = j % 10;
        revnumm += remainder * pow(10, digitss - 1);
    }

    cout << revnumm;
}

void revnum_m2(int n)
{
    // remove trail
    while (n % 10 == 0)
    {
        n /= 10;
    }

    // loop breaks with n = number without TZ

    int revnum = 0;

    // construct the revnum
    for (int i = n; i > 0; i /= 10)
    {
        revnum = revnum * 10 + (i % 10);
    }
    cout << revnum; // print the reversed number
}

int palindrome(int n)
{
    // reverse the number
    int revnum = 0;
    for (int i = n; i > 0; i /= 10)
    {
        revnum = revnum * 10 + (i % 10);
        // i =1357 => revnum = 7, 70+5, 750+3, 7530+1..
    }

    if (n == revnum)
    {
        return true;
    }
    else
        return false;
}

int gcd(int a, int b)
{
    // container for divisors
    vector<int> div1, div2;

    // adding divisors
    // for (int i = 0; i <= a; ++i) ❌ start from 1 to avoid division by zero
    for (int i = 1; i <= a; ++i) // ✅
    // or for(int i = 1; i<=a; i++)
    {
        if (a % i == 0)
        {
            div1.push_back(i);
        }
    }
    for (int i = 0; i <= b; ++i) // or for(int i = 1; i<=a; i++)
    {
        if (b % i == 0)
        {
            div2.push_back(i);
        }
    }

    // either create a new vector
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
    int gcd = *max_element(common.begin(), common.end());
    return gcd;
}
int main()
{
    // int n;
    // cin >> n;

    // int a, b;
    // cin >> a;
    // cin >> b;

    // DigitExtraction(n);
    // revnum_clean(n);
    // revnum_m2(n);
    // cout << palindrome(n); // 1 for true, 0 for false
    // cout << gcd(a, b);

    return 0;
}