#include <bits/stdc++.h>
using namespace std;

/*

// Search target element in row and column wise sorted matrix

- every row is sorted from left to right individually
- every column is sorted from top to bottom individually
- we have to return the co-ordinates of the target element in the array


1. Brute force Approach
- we find the element by traversing normally

- Time complexity -> O(n*m)
- Space complexity -> O(1)




2. Better Approach

- as we know that each row is sorted
- so we can perform binary search on each row individually
- and then we will get the element

- Time complexity -> O( log2m * n )




3. Optimal Approach

- so we will start from row = 0 and col as m-1
- and then we will have right to left as decreasing and top to bottom as increasing
- so this will help us in elimination
- we will eliminate the elements which are smaller or greater than the target element
- and we will move to the next row and next column

- the first and the last positions cannot be the starting positions as both sides are either increasing or decreasing
- we want one to be increasing and other to be decreasing


- Time complexity -> O(n + m) -> as we are going from one diagonal to other
- Space complexity -> O(1)


*/

int binary(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

pair<int, int> search_sorted_better(vector<vector<int>> matrix, int rows, int cols, int target)
{

    int index = 01;
    for (int i = 0; i < rows; i++)
    {
        index = binary(matrix[i], target);
        if (index != -1)
        {
            return {i, index}; // return the row and column of the target element
        }
    }

    return {-1, -1};
}

pair<int, int> search_sorted_optimal(vector<vector<int>> matrix, int rows, int cols, int target)
{
    // so here we are initializing the starting position of the algorithm which is top right
    int row = 0;
    int col = cols - 1;

    while (row < rows && cols >= 0)
    {

        // the while loop should run until we go to the next corner of the matrix
        // so the constraints are added accordingly

        if (matrix[row][col] == target)
            return {row, col};
        else if (matrix[row][col] < target)
        {
            // this means that we will we will increment the row
            row++;
        }
        else
        {
            // this means that we will decrement the column
            col--;
        }
    }

    return {-1, -1};
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

    // pair<int, int> coordinates = search_sorted_better(matrix, n, m, target);
    pair<int, int> coordinates = search_sorted_optimal(matrix, n, m, target);

    cout << "The target element " << target << " is found at the co-ordinate: (" << coordinates.first << ", " << coordinates.second << ")";

    return 0;
}