#include <bits/stdc++.h>
using namespace std;

/*

// Set Matrix zeros problem

- we will be given a matrix with 0's and 1's
- whichever co-ordinate has 0, its entire row and column should be marked as zeros in the matrix
- but, the new zeros that get formed due to this will not be considered for making 0's and 1's to the rows and cols
- only the zeros that are in the start only they will do that





1. Brute force solution

- we will iterate through each co-ordinate and the moment we find a zero we will do the process
- but we cannot directly convert all to zero, as algorithm will go wrong as we want changes from only starting zeros
- so first we will convert the entire row and col, containing zero as -1 and then follow the same process
- and at the end convert all the -1's to 0's by iteration all at once


Time complexity:
- first O(n*m) for iterating over the entire matrix
- O(n) for converting all rows to -1s and O(m) for converting all cols to -1s -> O(n+m)
- O(n*m) for converting all -1s to 0s

- Total time complexity: O(n*m)*O(n+m) + O(n*m) = O(n^3)
- Space complexity -> O(1)





2. Better solution

- so instead of traversing the entire matrix, we will just traverse once
- and check if in each col there is min(1,0) if there is then we will mark that column in a m size array
- and after the cols are marked that need to be zero we will make the required one's as zero

- for that we will need n and m size array initially all marked as zero
- now whenever we encounter a zero, mark those co ordinates in the new formed array as 1
- now at the end we will have which cols and which rows need to be zeros
- and then we will do a re-iteration and check into the new formed marked arrays, and mark the necessary 1's as 0's


- Time complexity -> O(n*m) + O(n*m) -> O(2*(n*m))
- Space complexity -> O(n) + O(m) for rows and cols tracker array -> O(n+m)




3. Optimal Approach
- so we will be not using extra arrays
- we will be taking the row[0]  as the col_tracker[cols] and col[0] as the row_tracker[rows]
- but there is a common element here if we do this
- so to get rid of that we will consider the size of row_tracker as full and col_tracker as one less
- so the common element will be only in the row tracker, so now to track that element in the col_tracker we will create a single extra variable as col0 = value
- so now we can start doing the same thing

- we will mark the co-ordinate of the row and the column tracker to be 0 if we get any zero
- if in row and col tracker if any element is 0 then we will keep it as it is as it is a zero and mark the other one as zero if it is not

- now for starting to check and make all the rows and cols as 0 we can't start from the row and col tracker elements as if its value will change then it will create a problem
- so for that we will start from the back and then go on marking 0's to all

- now we will solve the column tracker part first and then the row tracker part
- because if we do it reverse then the values of row tracker may get updated which may change the col tracker values


- Time complexity -> O(n*m) + (n*m) -> O(2*(n*m))
- Space Complexity -> O(1) ->  just using one extra variable


*/

void mark_row(vector<vector<int>> &matrix, int i, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void mark_col(vector<vector<int>> &matrix, int j, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void set_matrix_brute(vector<vector<int>> &matrix, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                mark_row(matrix, i, cols);
                mark_col(matrix, j, rows);
            }
        }
    }

    // making all the -1's to 0's
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

/*




*/

void set_matrix_better(vector<vector<int>> &matrix, int rows, int cols)
{

    int row_tracker[rows];
    int col_tracker[cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                row_tracker[i] = 1;
                col_tracker[j] = 1;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (row_tracker[i] == 1 || col_tracker[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

/*






*/

void set_matrix_optimal(vector<vector<int>> &matrix, int rows, int cols)
{

    // in the tracker the 0 part is not changing
    // the column tracker will be -> matrix[0][..]  -> horizontal
    // the row tracker will be -> matrix[...][0] -> vertical

    int col0 = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (matrix[i][j] == 0)
            {

                // we will make its row tracker and col tracker as 0

                // row tracker -> mark the i-th row
                matrix[i][0] = 0;

                // col tracker -> mark the j-th col
                // matrix[0][j] = 0;

                // location a31 -> if it is already zero then we have to mark a11 as zero as well
                // but we can't do that as we are taking it as a variable or else we will get a common point

                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    // because we need to mark atleast one of them as zero
                    col0 = 0;
                }
            }
        }
    }

    // after the marking part is done, we start from the end and then go on
    // but we ignore the 0th row and the 0th column

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {

            // if it is 1 then we have to check for the row and the col tracker
            if (matrix[i][j] != 0)
            {

                //  if the row tracker or the col tracker is marked as 0 then that element is 0

                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // now finally we are doing the col part
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < cols; j++)
        {
            // everyone on the first row will be zero
            matrix[0][j] = 0;
        }
    }

    // now for the row at the last
    if (col0 == 0)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    // Declaring matrix globally
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // set_matrix_brute(matrix, rows, cols);
    // set_matrix_better(matrix, rows, cols);
    set_matrix_optimal(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}