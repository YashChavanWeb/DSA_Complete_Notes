#include <bits/stdc++.h>
using namespace std;

/*

// Find the row with maximum no of 1s in the matrix
- every row will be sorted in the matrix
- incase there are multiple rows with maximum 1s then return the row with the smallest index




1. Brute force approach
- simply keep a counter that will count the no. of ones
- wherever we find greater we will update the max count and also the index
- and to get the minimum index only we will not update the same value
- so the count should always be > to be updated by max count

- Time complexity -> O(n*m)
- Space complexity -> O(1)



2. Optimized Approach

- if we treat each row here as an individual array
- we just have to find the first one, as the array is sorted
- we we figure out the first 1 then no of 1s in that row will be size - 1 index -> m - 2 = 3 ones will be present

- so to find the first 1 we can use any of the approaches below
    - lower bound (1)
    - upper bound (0)
    - first occurrence (1)

- Time complexity (n * log2m )
- Space complexity -> O(1)


*/

int row_with_max_brute(vector<vector<int>> matrix, int rows, int cols)
{

    // index of the row
    int idx = -1;
    // row with max ones
    int max_ones = -1;

    for (int i = 0; i < rows; i++)
    {
        int ctr = 0;
        for (int j = 0; j < cols; j++)
        {
            // if (matrix[i][j] == 1)
            //     ctr++;

            // or as all are 1s we can directly add as well
            ctr += matrix[i][j];
        }

        if (ctr > max_ones)
        {
            max_ones = ctr;
            idx = i;
        }
    }

    return idx;
}

int lower_bound_sol(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= x)
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int row_with_max_optimal(vector<vector<int>> matrix, int rows, int cols)
{

    int max_Cnt = 0;
    int idx = -1;

    for (int i = 0; i < rows; i++)
    {
        int first_one_index = lower_bound_sol(matrix[i], cols, 1);
        int no_of_ones = cols - first_one_index;

        if (no_of_ones > max_Cnt)
        {
            max_Cnt = no_of_ones;
            idx = i;
        }
    }

    // return the index of the column where we find that
    return idx;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int row = row_with_max_brute(matrix, n, m);
    cout << "The row with maximum 1's is row : " << row;

    return 0;
}