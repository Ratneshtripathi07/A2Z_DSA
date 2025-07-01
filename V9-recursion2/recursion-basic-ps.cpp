#include <bits/stdc++.h>

using namespace std;

// int cnt = 1; // for printN_1 // cnt is 1 because were printing before condition check.
void printN_1(int n)
{
    cout << "xyz" << endl;
    int cnt;
    if (cnt == n)
        return;
    cnt++;

    printN_1(n);
}

void printn_2(int n)
{
    static int cnt = 0;
    if (cnt == n)
    {
        return;
    }
    cout << "hi there" << endl;
    cnt++;
    printn_2(n);
}

void p1ton(int n)
{
    static int cnt = 0;
    static int num = 0;
    if (cnt == n)
        return;
    cnt++;
    num += 1;
    cout << num << endl;

    p1ton(n);
}

void pnto1(int n)
{
    static int cnt = 0;
    static int num = n;
    if (cnt == n)
        return;
    cout << num << endl;
    cnt++;
    num--;
    pnto1(n);
}

// int p1tonSum(int n)
// {
//     static int cnt = 0;
//     int sum = 0;
//     if (cnt > n)
//         return sum;
//     cnt++;
//     sum += cnt;
//     p1tonSum(n);
// }

int p1tonSum(int n, int cnt = 0)
{
    // Base case: stop when cnt exceeds n
    if (cnt > n)
    {
        return 0;
    }
    // Recursive case: add current cnt and recurse
    return cnt + p1tonSum(n, cnt + 1);

    // n = 4
}

int sum1toN(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
        return n + sum1toN(n - 1);
}

int factorialN(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorialN(n - 1);
}

int ArrayReverse(int arr[], int n)
{
}

int main()
{
    int n;
    cin >> n;
    // printN_1(n);
    // printn_2(n);
    // p1ton(n);
    // pnto1(n);
    // -----------------------------------
    // int p1tonSumI = p1tonSum(n);
    // cout << p1tonSumI;
    // --------------------------------------

    // cout << p1tonSum(n);

    cout << factorialN(n);

    return 0;
}
