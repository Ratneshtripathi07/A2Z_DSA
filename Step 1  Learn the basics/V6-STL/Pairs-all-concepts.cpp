// pairs are simple containers like list in python and its content can be accessed

#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, string> getPersonDetails()
{
    return make_pair(1, "John");
}

int main()
{
    // 1. Creating pairs
    pair<int, string> person(1, "John");
    cout << "Person ID: " << person.first << ", Name: " << person.second << endl;

    // 2. Using make_pair
    auto person2 = make_pair(2, "Doe");
    cout << "Person ID: " << person2.first << ", Name: " << person2.second << endl;

    // 3. Modifying pair elements
    person2.first = 3;
    person2.second = "Jane";
    cout << "Updated Person ID: " << person2.first << ", Name: " << person2.second << endl;

    // 4. Using pairs in map
    map<int, string> people;
    people.insert(make_pair(1, "John"));
    people[2] = "Doe";

    for (const auto &p : people)
    {
        cout << "Person ID: " << p.first << ", Name: " << p.second << endl;
    }

    // 5. Using pairs in vector
    vector<pair<int, string>> peopleVec = {{1, "John"}, {2, "Doe"}};
    for (const auto &p : peopleVec)
    {
        cout << "Person ID: " << p.first << ", Name: " << p.second << endl;
    }

    // 6. Sorting a vector of pairs
    vector<pair<int, string>> peopleVec2 = {{2, "Doe"}, {1, "John"}};
    sort(peopleVec2.begin(), peopleVec2.end());
    for (const auto &p : peopleVec2)
    {
        cout << "Person ID: " << p.first << ", Name: " << p.second << endl;
    }

    // 7. Custom sorting a vector of pairs
    vector<pair<int, string>> peopleVec3 = {{2, "Doe"}, {1, "John"}};
    sort(peopleVec3.begin(), peopleVec3.end(), [](const auto &a, const auto &b)
         {
             return a.second < b.second; // Sort by name
         });
    for (const auto &p : peopleVec3)
    {
        cout << "Person ID: " << p.first << ", Name: " << p.second << endl;
    }

    // 8. Returning pairs from functions
    auto result = getPersonDetails();
    cout << "Person ID: " << result.first << ", Name: " << result.second << endl;

    return 0;
}

// by gpt

#include <iostream>
#include <utility> // for pair
#include <vector>
#include <map>
#include <tuple>

using namespace std;

int main()
{
    // 1. Basic declaration and initialization
    pair<int, string> p1;                // default initialization
    p1 = make_pair(1, "One");            // using make_pair
    pair<int, string> p2(2, "Two");      // direct initialization
    pair<int, string> p3 = {3, "Three"}; // uniform initialization

    cout << "p1: (" << p1.first << ", " << p1.second << ")\n";
    cout << "p2: (" << p2.first << ", " << p2.second << ")\n";
    cout << "p3: (" << p3.first << ", " << p3.second << ")\n\n";

    // 2. Nested pair
    pair<int, pair<string, double>> p4 = {4, {"Four", 4.4}};
    cout << "p4: (" << p4.first << ", (" << p4.second.first << ", " << p4.second.second << "))\n\n";

    // 3. Comparing pairs (lexicographical order)
    pair<int, int> a = {1, 5};
    pair<int, int> b = {1, 10};
    if (a < b)
        cout << "a is less than b\n\n";

    // 4. Swapping pairs
    cout << "Before swap: a = (" << a.first << ", " << a.second << "), b = (" << b.first << ", " << b.second << ")\n";
    swap(a, b);
    cout << "After swap: a = (" << a.first << ", " << a.second << "), b = (" << b.first << ", " << b.second << ")\n\n";

    // 5. Using pair in a vector
    vector<pair<int, string>> vec;
    vec.push_back({1, "One"});
    vec.emplace_back(2, "Two");

    cout << "Vector of pairs:\n";
    for (auto &p : vec)
        cout << "(" << p.first << ", " << p.second << ")\n";
    cout << endl;

    // 6. Using pair in a map
    map<int, string> mp;
    mp.insert({1, "Apple"});
    mp[2] = "Banana";

    cout << "Map contents:\n";
    for (auto &entry : mp)
        cout << "(" << entry.first << ", " << entry.second << ")\n";
    cout << endl;

    // 7. Returning pair from a function
    auto getCoordinates = []() -> pair<int, int>
    {
        return {10, 20};
    };

    pair<int, int> coords = getCoordinates();
    cout << "Returned pair from function: (" << coords.first << ", " << coords.second << ")\n\n";

    // 8. Structured binding (C++17 and above)
#if __cplusplus >= 201703L
    auto [x, y] = coords;
    cout << "Structured binding: x = " << x << ", y = " << y << "\n\n";
#endif

    // 9. Pair with custom types
    struct Person
    {
        string name;
        int age;
    };
    Person person = {"Alice", 25};
    pair<int, Person> p5 = {1, person};
    cout << "p5: (" << p5.first << ", " << p5.second.name << ", " << p5.second.age << ")\n";

    return 0;
}
