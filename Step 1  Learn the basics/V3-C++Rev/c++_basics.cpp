/*
    C++ Basics

    This file demonstrates basic C++ syntax and features, including:
    - Input/Output
    - Variable declarations
    - Conditional statements (if-else, switch)
    - Loops (for, while)
    - Functions (including pass by value and pass by reference)
    - Arrays
    - String usage
*/

// Include necessary headers
#include <iostream>
#include <string>
using namespace std;

// Function to add two integers
int add(int a, int b)
{
    return a + b;
}

// Pass by value: does not modify the original variable
void increment(int a)
{
    a++;
}

// Pass by reference: modifies the original variable
void incrementRef(int &a)
{
    a++;
}

int main()
{
    // 1. Input/Output
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old." << endl;

    // 2. Variable Declarations
    int x = 10;
    float y = 5.5f;
    char ch = 'A';
    bool isValid = true;
    double d = 3.14159;

    // 3. Conditional Statements
    int n = 10;
    if (n % 2 == 0)
    {
        cout << n << " is Even" << endl;
    }
    else
    {
        cout << n << " is Odd" << endl;
    }

    int day = 3;
    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    default:
        cout << "Invalid day" << endl;
    }

    // 4. Arrays and Loops
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 5. String Usage
    string name = "Alex";
    cout << "Hello, " << name << endl;

    // 6. For Loop
    cout << "For loop from 1 to 5: ";
    for (int i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    // 7. While Loop
    cout << "While loop from 1 to 5: ";
    int i = 1;
    while (i <= 5)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // 8. Functions
    cout << "add(3, 4) = " << add(3, 4) << endl;

    // 9. Pass by Value and Reference
    int val = 5;
    increment(val); // val is still 5
    cout << "After increment(val): " << val << endl;
    incrementRef(val); // val becomes 6
    cout << "After incrementRef(val): " << val << endl;

    return 0;
}
