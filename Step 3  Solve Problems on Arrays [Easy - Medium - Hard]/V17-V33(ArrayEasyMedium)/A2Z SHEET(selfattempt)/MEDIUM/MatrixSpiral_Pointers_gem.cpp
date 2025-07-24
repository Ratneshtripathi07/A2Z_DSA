#include <iostream>      // For input/output operations (cin, cout)
#include <vector>        // For using std::vector
#include <bits/stdc++.h> // Common header for competitive programming, includes many standard libraries

// Use the std namespace to avoid writing std:: repeatedly.
using namespace std;

// Function to traverse a 2D matrix in a spiral order
// and return the elements in a 1D vector.
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // Get the number of rows (m) and columns (n) of the matrix.
    int m = matrix.size();
    // If the matrix is empty (no rows), return an empty vector.
    if (m == 0)
    {
        return {};
    }
    int n = matrix[0].size();

    // Vector to store the elements in spiral order.
    vector<int> ans;

    // Initialize boundary pointers for the spiral traversal.
    int top = 0;        // Represents the top row index
    int bottom = m - 1; // Represents the bottom row index
    int left = 0;       // Represents the left column index
    int right = n - 1;  // Represents the right column index

    // Loop until the boundaries cross each other, meaning all elements have been traversed.
    while (top <= bottom && left <= right)
    {
        // 1. Traverse Right (from left to right along the current top row)
        // Add elements from matrix[top][left] to matrix[top][right].
        for (int j = left; j <= right; ++j)
        {
            ans.push_back(matrix[top][j]);
        }
        top++; // Move the top boundary down, as the top row has been processed.

        // 2. Traverse Down (from top to bottom along the current rightmost column)
        // Add elements from matrix[top][right] to matrix[bottom][right].
        for (int i = top; i <= bottom; ++i)
        {
            ans.push_back(matrix[i][right]);
        }
        right--; // Move the right boundary left, as the rightmost column has been processed.

        // 3. Traverse Left (from right to left along the current bottom row)
        // This step is executed only if there's still a valid bottom row to traverse.
        // This check prevents double-counting elements in a single-row matrix.
        if (top <= bottom)
        {
            // Add elements from matrix[bottom][right] to matrix[bottom][left].
            for (int j = right; j >= left; --j)
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--; // Move the bottom boundary up, as the bottom row has been processed.
        }

        // 4. Traverse Up (from bottom to top along the current leftmost column)
        // This step is executed only if there's still a valid left column to traverse.
        // This check prevents double-counting elements in a single-column matrix.
        if (left <= right)
        {
            // Add elements from matrix[bottom][left] to matrix[top][left].
            for (int i = bottom; i >= top; --i)
            {
                ans.push_back(matrix[i][left]);
            }
            left++; // Move the left boundary right, as the leftmost column has been processed.
        }
    }

    // Return the vector containing elements in spiral order.
    return ans;
}

int main()
{
    // Redirect standard input from "input.txt" and standard output to "output.txt".
    // This is common in competitive programming for testing.
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Read matrix dimensions.
    int m;
    cin >> m;
    int n;
    cin >> n;

    // Declare and initialize a 2D vector (matrix) with dimensions m x n.
    // All elements are default-initialized to 0.
    vector<vector<int>> matrix(m, vector<int>(n));

    // Read elements into the matrix from input.
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // Call the spiralOrder function to get the result.
    vector<int> result = spiralOrder(matrix);

    // Print the elements of the result vector.
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0; // Indicate successful execution.
}
