#include <bits/stdc++.h>
using namespace std;

/*

// Maximal Rectangle

- we are given a 2D matrix of n*m with only 0s and 1s
- give the area of maximal rectangle which has all 1s in it




Approach

- here we can use the concept of largest rectangle in histogram
- each col 1s can act as bars of 1 and then we can compute the largest rectangle
- but for that we cannot just iterate
- for that we can use the concept of prefix sum
- we will convert the matrix to its prefix sum and then have the bar values automatically
- then we can compute the rectangle area

- Time complexity -> O(N*M) + O(N*2M) - prefix sum + traversal * max histogram rectangle
- Space Complexity -> O(N*M) + O(N) - prefix sum + stack


*/

vector<vector<int>> prefixSum(vector<vector<int>> matrix, int rows, int cols)
{

    vector<vector<int>> pSum(rows, vector<int>(cols));

    // so we will traverse col wise as we want to write the additions for the bars
    for (int j = 0; j < cols; j++)
    {
        int sum = 0;

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][j] == 0)
                sum = 0;
            else
                sum += matrix[i][j];

            // and then finally we will update the prefix sum array
            pSum[i][j] = sum;
        }
    }

    return pSum;
}

int largest_rect_in_histogram(vector<int> arr)
{

    // basic declarations
    stack<int> st;
    int maxArea = -1;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        // first we will keep popping the stack for greater elements
        while (!st.empty() && arr[st.top()] > arr[i])
        {

            // if this is the case then we got out element
            int element = st.top();
            st.pop();

            // compute the pse and nse
            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            // now compute the area
            int area = arr[element] * (nse - pse - 1);
            maxArea = max(area, maxArea);
        }

        // and then after all this we will push the index of element in stack
        st.push(i);
    }

    // if there are still elements remaining in the stack
    while (!st.empty())
    {
        int element = st.top();
        st.pop();

        // compute the pse and nse
        int nse = n;
        int pse = st.empty() ? -1 : st.top();

        // compute area
        int area = arr[element] * (nse - pse - 1);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int maximal_rectangle(vector<vector<int>> &matrix, int rows, int cols)
{

    // first we have to make the prefix sum 2D array ready
    vector<vector<int>> pSum = prefixSum(matrix, rows, cols);

    int maxArea = 0;

    // we have to traverse the row (which is considered as a single array) one by one
    for (int i = 0; i < rows; i++)
    {

        maxArea = max(maxArea, largest_rect_in_histogram(pSum[i]));
    }

    return maxArea;
}

int main()
{
    int rows = 4;
    int cols = 5;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    matrix = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "  ";
        }

        cout << endl;
    }

    int maxArea = maximal_rectangle(matrix, rows, cols);
    cout << maxArea;

    return 0;
}