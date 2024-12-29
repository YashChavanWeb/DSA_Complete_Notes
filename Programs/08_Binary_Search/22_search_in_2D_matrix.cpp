#include <bits/stdc++.h>
using namespace std;

/*

// Search in a sorted 2D Matrix
- we will be given a target and then if that target is present in the matrix then we have to return true or else false


1. Brute force Approach
- we will go through the entire matrix and check if the target element is there or not

- Time complexity -> O(n*m)
- Space complexity -> O(1)




2. Better Approach

- as the 2D matrix is sorted we can check in ranges
- so when we are on a specific row, we will check whether the target element lies between the first and last element in the row
- if it lies then only we will search for it in that row or else we will move to the next row
- so for searching into the row, as it is a 1D array itself so we can use binary search

- Time complexity -> O(n + log2m) ->> + because we are just performing binary search only once
- Space complexity -> O(1)




3. Optimal Approach

- as the entire matrix is sorted, so if we can flatten the entire matrix to a single 1D array then it will be super easy
- but we cannot do that directly as it will take O(n*m) complexity just to flatten every element

- so we need a logic, to convert a 1D co-ordinate to a 2D co-ordinate because binary search we know on 1D so if we convert to 2D then our job is done

- we have a index and to find its
    row -> index / cols
    col -> index % cols

- intuition behind how this logic works


*/

bool search_2D_brute(vector<vector<int>> matrix, int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

bool binary(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

bool search_2D_better(vector<vector<int>> matrix, int rows, int cols, int target)
{
    bool result;

    for (int i = 0; i < rows; i++)
    {
        // check if the target is in the row
        if (matrix[i][0] <= target && target <= matrix[i][cols - 1])
        {
            // perform binary search for finding the element
            result = binary(matrix[i], target);
        }
    }

    return result;
}

bool search_2D_optimal(vector<vector<int>> matrix, int rows, int cols, int target)
{
    int low = 0, high = (rows * cols - 1);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // calculate row and col as well
        int row = mid / cols, col = mid % cols;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    // bool result = search_2D_brute(matrix, n, m, target);
    // bool result = search_2D_better(matrix, n, m, target);
    bool result = search_2D_optimal(matrix, n, m, target);

    if (result)
    {
        cout << "The target is found in the matrix";
    }
    else
    {
        cout << "The target is not found in the matrix";
    }

    return 0;
}