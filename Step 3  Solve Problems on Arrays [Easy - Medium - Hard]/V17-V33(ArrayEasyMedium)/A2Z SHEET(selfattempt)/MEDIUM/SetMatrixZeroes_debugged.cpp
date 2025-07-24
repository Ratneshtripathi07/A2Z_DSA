#include <vector>
#include <iostream>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns

    // Create boolean arrays to mark rows and columns
    vector<bool> row(m, false); // false means no zero in row
    vector<bool> col(n, false); // false means no zero in column

    // Step 1: Mark rows and columns containing zeros
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // Step 2: Set entire rows and columns to zero
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    // Example usage
    vector<vector<int>> matrix = {{1, 1, 1},
                                  {1, 0, 1},
                                  {1, 1, 1}};

    setZeroes(matrix);

    // Print result
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}