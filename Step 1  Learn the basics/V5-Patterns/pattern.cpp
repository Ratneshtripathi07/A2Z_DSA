#include <bits/stdc++.h> // include all the standard library including the input output stream library.

using namespace std;

void print1(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print8(int n)
{

    // Loop through each row (except the last one)
    for (int i = 1; i < n; i++)
    {
        // Print leading underscores
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "_";
        }

        // Print asterisks in the middle
        for (int j = 1; j <= 2 * n - 2 * i - 1; j++)
        {
            cout << "*";
        }

        // Print trailing underscores
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "_";
        }

        // Move to next line
        cout << endl;
    }

    // return 0;
}

void print7(int n)
{
    for (int i = 1; i < n; i++)
    {

        // Inner loop to print the leading spaces
        // The number of spaces is (n - i)
        for (int j = 1; j < n - i; j++) // it's not j<=n-1 cuz n-1 is the last row
        {
            cout << "_";
        }

        // Inner loop to print the stars
        // The number of stars is (2 * i - 1)
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        // Inner loop to print the trailing spaces
        for (int j = 1; j < n - i; j++)
        {
            cout << "_";
        }

        // Move to the next line after each row is printed
        cout << endl;
    }
}

// for pattern 9
// int main()
// {

//     int n;
//     cin >> n;
//     print7(n);
//     print8(n);
//     return 0;
// }

void print10(int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
// for pattern 10 p1+p10
// int main()
// {

//     int n;
//     cin >> n;
//     print1(n);
//     print10(n);
//     return 0;
// }

void print11_1(int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                cout << "0";
            }
            else if (i % 2 == 0 && j % 2 != 0)
            {
                cout << "1";
            }
            else if (i % 2 != 0 && j % 2 == 0)
            {
                cout << "1";
            }
            else if (i % 2 != 0 && j % 2 != 0)
            {
                cout << "0";
            }
        }
        cout << endl;
    }
}

void print11_2(int n) // m-2 by striver
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j < i + 1; j++)
        { // assuming you want to print i+1 numbers in each row
            cout << start;
            start = 1 - start; // update the value for next col. iteration
        }
        cout << endl;
    }
}

// p12
void print12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void print13_1(int n)
{
    int start = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << start + 1 << " "; // iteration 1 = 0+1 = 1, iteration 2 = 1+1 = 2
            start = start + 1;        // value of start is updated to 1, then 2, then 3, then 4, then 5
        }
        cout << endl;
    }
}

void print13_2(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num << "-";
            num++;
        }
        cout << endl;
    }
}

void print15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch < 'A' + (n - i); ch++)

        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void print16(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)

        {
            char ch = 'A';
            // cout << ch + i << " "; it prints 65, 66 66,.. cuz i = int
            cout << char(ch + i) << " ";
        }
        cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     char ch = 'A' + i; // Move this outside inner loop
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }

    // ... existing code ...
}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Space on left
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // Character on left
        for (int j = 0; j < i + 1; j++)
        {
            cout << (char)('A' + j);
        }

        // Character on right
        for (int j = i - 1; j >= 0; j--)
        {
            cout << (char)('A' + j);
        }

        // Space on right
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        cout << endl; // Move to the next line after each row
    }
}
void print17_2(int n)
{
    // STRIVER'S APPROACH
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // characters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++; // NOTE: ITS "UPDATING" THE CH VALUE
            else
                ch--;
        }

        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + (n - i);
        // for (int j = n - i; j >= 0; j++)infinite loop
        for (int j = 0; j <= i; j++)
        {
            cout << char(ch + j) << " ";
        }
        cout << endl;
    }
}

void print21(int n)
{
    for (int i = 0; i <= n; i++)
    {
        // boundary conditions
        if (i == 0 || i == n)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j <= n; j++)
            {
                if (j == 0 || j == n)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}

void print22_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        // left side
        for (int j = 1; j <= i; j++)
        {
            cout << n - j + 1;
        }
        // main
        for (int j = 0; j <= 2 * (n - i) - 1; j++)
        {
            cout << n - i;
        }
        // right side
        // for (int j = i; j >= 0; j--) for j = 0, it prints a (4-o+1=) 5 at the end.
        for (int j = i; j > 0; j--)
        {
            cout << n - j + 1;
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    print22_1(n);
    return 0;
}