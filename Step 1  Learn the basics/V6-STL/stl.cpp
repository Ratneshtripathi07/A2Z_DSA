#include <bits/stdc++.h>
using namespace std;

// making function using void

void pairuse()
{
    // creating a pair
    pair<int, int> age = {11, 12};
    //
    pair<int, string> age_name(10, "staffy");
    // using make pair -- use of auto
    auto livingdetails = make_pair("lkocity", 22);

    // nested pair (pair inside a pair)
    pair<int, pair<int, int>> x(5, {2, 3});

    // array using pair
    pair<int, int> A[] = {{1, 2}, {2, 3}, {3, 4}, {5, 6}};

    // calling..

    cout << age.second << endl;
    cout << age_name.second << endl;
    cout << livingdetails.first << endl;
    cout << x.second.second << endl;
    cout << A[2].first << endl;
}

void vectoruse()
{
    // empty vector
    vector<int> v;
    // push/emplace_back
    v.push_back(1);
    v.emplace_back(2);
    //
    // Vector Initialization
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // vec of pairs
    //  vector<pair<int,int>> v11({2,3}); //ERROR
    vector<pair<int, int>> v1 = {{1, 2}};
    // or
    vector<pair<int, int>> v1({{1, 2}});

    // The double braces {{1, 2}} are needed because:
    // Outer {} is for initializing the vector,
    // Inner {} is for initializing the pair.

    //
    vector<int> v2(5, 100); // no of times, initialized with
    //
    // iterator
    vector<int>::iterator IT = v.begin();

    IT++;

    // Use of * (it gives/takes the value of the memory location)

    cout << *(IT) << " " << endl;
}

int main()
{
    pairuse();
}