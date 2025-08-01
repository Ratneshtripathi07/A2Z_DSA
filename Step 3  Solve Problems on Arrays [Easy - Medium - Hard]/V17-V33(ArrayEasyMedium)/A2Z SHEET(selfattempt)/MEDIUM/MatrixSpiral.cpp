#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    int m = matrix.size();    // length of col == no of rows
    int n = matrix[0].size(); // length of rows == no of coloumns

    vector<int> ans;
    // 1 Row matrix
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            ans.push_back(matrix[0][i]);
        }
        return ans;
    }
    else if (n == 1) // 1 col matrix
    {
        for (int i = 0; i < m; i++)
        {
            ans.push_back(matrix[i][0]);
        }
        return ans;
    }

    int cnt = 0;
    for (int i = 0; i < m * n; i++)
    {

        // row-0 / FIRST ROW
        for (int j = i; j < n - i; j++)
        {
            ans.push_back(matrix[i][j]);
            cnt++;
            if (cnt == m * n)
            {
                return ans;
            }
        }

        // LAST COL / n-1-i th row [(n-i;i=0)th coloumn thn (n-i; i= 1)th then ....0]

        for (int j = i + 1; j < m - i; j++)
        {
            ans.push_back(matrix[j][n - i - 1]);
            cnt++;
            if (cnt == m * n)
            {
                return ans;
            }
        }

        // m-1-i th row / LAST ROW  ...
        for (int j = n - i - 2; j >= 0 + i; j--)
        {
            ans.push_back(matrix[m - i - 1][j]);
            cnt++;
            if (cnt == m * n)
            {
                return ans;
            }
        }

        // i - th coloumn / FIRST COL

        for (int j = m - 2 - i; j > 0 + i; j--)
        {
            ans.push_back(matrix[j][i]);
            cnt++;
            if (cnt == m * n)
            {
                return ans;
            }
        }
    }
    return ans; // comment this return to see that compiler throws error
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    /*
    3 3
    1 2 3
    4 5 6
    7 8 9
    */
    int m;
    cin >> m;
    int n;
    cin >> n;

    /*
    ❌ init of 2D Vector (matrix)
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cin>>j;
            matrix.push_back(matrix[j][i]);
        }
    }

    */

    vector<vector<int>> matrix(m, vector<int>(n));

    /*

    initialization/declaration of a 2D matrix
    vector<vector<int>> matrix: Declares a 2D vector matrix(vector of vectors) where each element is an integer.
    (m, vector<int>(n)): Initializes the 2D vector with m rows/m Copies of a vector (of n integers and all = 0)

    */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}
