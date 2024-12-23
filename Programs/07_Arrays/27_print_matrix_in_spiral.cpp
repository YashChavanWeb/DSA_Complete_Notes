#include <bits/stdc++.h>
using namespace std;

/*

// Print Matrix in spiral order

- It just one solution and that is the optimal solution

1. Optimal Approach
- it is a pattern, we go right - down - left - top


- Time complexity -> O(n*m)  - loops are written with all the cases
- Space complexity -> O(n*m)

*/

vector<int> spiral_optimal(vector<vector<int>> &matrix)
{
    // new array for pushing the elements
    vector<int> ans;

    // first defining the size of row and column
    int rows = matrix.size();
    int cols = matrix[0].size();

    // declaring the 4 pointers of left right top and bottom
    int left = 0, right = cols - 1;
    int top = 0, bottom = rows - 1;

    // we will keep repeating this cycle until left <= right and top <= bottom
    while (left <= right && top <= bottom)
    {
        // first step -> left to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // next step -> top to bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // what if there is only one single row, then for that we will have to see whether the top <= bottom - because in this case the top will become 1 but bottom is still 0

        if (top <= bottom)
        {
            // next step -> right to left
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // now here if we reach the the bottom and there is no top (even n*n) then for that there is no check
        // so before going from bottom to the top first check if the top exists or not

        if (left <= right)
        {
            // next step -> bottom to top
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = spiral_optimal(matrix);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}