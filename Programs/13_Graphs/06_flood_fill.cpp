#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &res, vector<vector<int>> &image,
         int iniColor, int newColor, int drow[], int dcol[])
{
    res[row][col] = newColor;

    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (
            nrow >= 0 && nrow < n &&
            ncol >= 0 && ncol < m &&
            image[nrow][ncol] == iniColor && res[nrow][ncol] != newColor)
        {

            res[nrow][ncol] = newColor;
            dfs(nrow, ncol, res, image, iniColor, newColor, drow, dcol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor)
{

    vector<vector<int>> res = image;

    int iniColor = image[sr][sc];

    int n = image.size();
    int m = image[0].size();

    // deltas
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dfs(sr, sc, res, image, iniColor, newColor, drow, dcol);
        }
    }

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
