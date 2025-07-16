// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * Demonstrates the usage of std::pair in C++.
 */
void explainPair()
{
    // Create a pair with two integer elements
    pair<int, int> p = {1, 3};
    cout << "Simple Pair: " << p.first << " " << p.second << endl;

    // Create a nested pair (pair within a pair)
    pair<int, pair<int, int>> nestedP = {1, {3, 4}};
    cout << "Nested Pair: " << nestedP.first << " "
         << nestedP.second.second << " " << nestedP.second.first << endl;

    // Create an array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << "Array of Pairs (second element of index 1): " << arr[1].second << endl;
}

void explainVector()
{
    // Create an empty vector
    vector<int> v;

    // Add elements to the vector using push_back
    v.push_back(1);

    // Add elements to the vector using emplace_back
    v.emplace_back(2);

    // This will cause a compilation error because v is a vector of integers
    // and we're trying to push_back a pair of integers.
    // v.push_back({1, 2});

    // to solve it:

    // Create a vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    // —-------------------------------------------------------------------------
    // —-------------------------------------------------------------------------

    // Create a vector with 5 elements, all initialized to 100

    vector<int> v3(5, 100); // output 100,100,100,100,100

    // operation:
    // Add values 1 through 5 to the corresponding elements in v3

    for (int i = 0; i < 5; i++)
    {
        v3[i] += i + 1;
    } // Output: v3[0] = 101, v3[1] = 102, v3[2] = 103, v3[3] = 104, v3[4] = 105

    // —-------------------------------------------------------------------------
    // —-------------------------------------------------------------------------

    // Create a vector with 5 default-constructed elements
    vector<int> v4(5);

    // Create a copy of v3
    vector<int> v2(v3);

    // Create an iterator to the beginning of the vector
    vector<int>::iterator it = v.begin();

    // Move the iterator to the next element
    it++;

    // Print the value at the current iterator position
    cout << *(it) << endl;
}

int vector_IteratorUse()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // Basic iterator usage
    vector<int>::iterator it = v.begin(); // points to 10
    it++;                                 // now points to 20
    cout << "After it++: " << *it << endl;

    it = it + 2; // moves to 40
    cout << "After it + 2: " << *it << endl;

    // Accessing elements
    cout << "v[0]: " << v[0] << ", v.at(0): " << v.at(0) << endl;
    cout << "v.back(): " << v.back() << endl;

    // Iterating using iterator
    cout << "Using iterator: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Iterating using auto
    cout << "Using auto: ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iterators
    cout << "Using reverse_iterator (rbegin to rend): ";
    for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;

    // Range-based for loop
    cout << "Using range-based for loop: ";
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

int main()
{
    explainPair();
    return 0;
}