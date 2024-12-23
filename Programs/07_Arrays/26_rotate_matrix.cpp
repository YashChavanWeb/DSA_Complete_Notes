#include <bits/stdc++.h>
using namespace std;

/*
// Rotate matrix by 90 degrees

1. Brute force solution
- here we will consider a new matrix and store the ans in there
- the pattern here we observe is
[0][0] -> [0][3]
[0][1] -> [1][3]
[0][2] -> [2][3]
[0][3] -> [3][3]

- so here we can observe that the j that is there is the i for the rotated matrix
- also the next index can be related as
i -> (n-1) + i -> (4-1) + i -> 3

- Time complexity -> O(n^2)
- Space complexity -> O(n^2)




2. Optimal Approach
- we don't have to use any extra space
- we have to solve in the same matrix
- so we observe that the cols is just reversed into the rows

- so to convert ocls into rows we do transpose of matrix
- and then to reverse we reverse each row of the matrix

- how to transpose the matrix
    - the diagonals will remain as it is
    - then all elements of [i][j] are swapped with [j][i]
- for 0 we have to traverse from 1 to 3, for 1 traverse from 2 to 3
- so for i travel from i+1 to n-1

- reverse every row

- Time complexity -> O(n/2) + O(n/2) -> O(n)
- Space complexity -> O(1)



*/

vector<vector<int>> rotate_brute(vector<vector<int>> matrix, int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));

    // Rotate 90 degrees clockwise by swapping positions
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Place the element from the original matrix to the rotated matrix
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }

    return ans;
}

void rotate_optimal(vector<vector<int>> &matrix, int n)
{
    // Transpose the matrix
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse the rows
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Rotate the matrix using the brute-force method
    // vector<vector<int>> ans = rotate_brute(matrix, n);

    // // Print the rotated matrix
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    rotate_optimal(matrix, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}