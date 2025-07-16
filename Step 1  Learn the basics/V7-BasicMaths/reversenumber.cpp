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

void ReverseNumber_0(int n)
{
    // int digits = 0;
    // // for (int i = n; i > 0; i / 10) // endless loop
    // for (int i = n; i > 0; i /= 10)
    // {
    //     digits += 1;
    // }
    // int x = digits;

    // int revnum = 0;

    // for (int j = n; j > 0; j /= 10)
    // {
    //     for (int k = 1; k < x; k++)
    //         if (n % 10 != 0)
    //         {
    //             int y = pow(10, x - k);
    //             int revnum_x = y * (j % 10);
    //             revnum += revnum_x;
    //         }
    //         else
    //         {
    //             continue;
    //         }
    // }
    // cout << revnum;
}

void revnum_1(int n) // ✅
{
    // int digitss = DigitExtraction(n); //❌ it will count digits in the og num
    int revnumm = 0;
    // for (int j = n; j > 0; j /= 10)
    while (n % 10 == 0 && n > 0)
    {
        n /= 10;
    }

    int digitss = DigitExtraction(n); // count digits in the cleaned number

    // int new_n = n; // not needed though. gets updated by the while loop
    // for (int j = new_n; j > 0; j /= 10, digitss--)

    for (int j = n; j > 0; j /= 10, digitss--)
    {
        int remainder = j % 10;
        revnumm += remainder * pow(10, digitss - 1);
    }

    // for (int j = n; j > 0; j /= 10, digitss--)
    // {
    // if (n % 10 == 0 && n != 0)
    // {
    //     n /= 10;
    // }
    // else
    // {
    //     int k = (j % 10) * pow(10, digitss - 1);
    //     revnumm += revnumm + k;
    // }

    // this logic is flawed cuz zeroes should be removed first
    // }
    cout << revnumm;
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
        // i =1357 => revnum = 7, 70+5, 750+3, 7530+1..
    }
    cout << revnum; // print the reversed number
}

// for passing all test cases:
int reverse(int x)
{
    long long res = 0;
    long long temp = x; // cast to long long
    int sign = (temp < 0) ? -1 : 1;
    temp = abs(temp);

    while (temp > 0)
    {
        res = res * 10 + temp % 10;
        temp /= 10;
    }

    res *= sign;

    if (res > INT_MAX || res < INT_MIN)
    {
        return 0;
    }

    return (int)res;
}

int main()
{
    int n;
    cin >> n;
    // DigitExtraction(n);
    // ReverseNumber_0(n);
    // revnum_clean(n);
    revnum_m2(n);
    return 0;
}