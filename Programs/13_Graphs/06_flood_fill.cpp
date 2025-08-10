#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &res, vector<vector<int>> &image,
         int iniColor, int newColor, int drow[], int dcol[])
{
    // Fill the current cell with the new color
    res[row][col] = newColor;

    int n = image.size();
    int m = image[0].size();

    // Explore all 4 directions (up, right, down, left)
    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        // Check if the new cell is valid and has the initial color
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == iniColor && res[nrow][ncol] != newColor)
        {
            // Recursively call dfs for the new cell
            dfs(nrow, ncol, res, image, iniColor, newColor, drow, dcol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor)
{
    vector<vector<int>> res = image;

    int iniColor = image[sr][sc];

    // No need to do anything if the initial color is the same as the new color
    if (iniColor == newColor)
        return res;

    int n = image.size();
    int m = image[0].size();

    // Directional deltas for up, right, down, left
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // Start the flood fill from the initial position
    dfs(sr, sc, res, image, iniColor, newColor, drow, dcol);

    return res;
}

int main()
{
    // Test grid
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int sr = 1, sc = 1;
    int color = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    cout << "Filled Image:" << endl;
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
