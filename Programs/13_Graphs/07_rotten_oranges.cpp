#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int freshCount = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2)
            {
                visited[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else
            {
                visited[i][j] = 0;
            }

            if (grid[i][j] == 1)
            {
                freshCount++;
            }
        }
    }

    // deltas
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    int tm = 0;
    int count = 0;

    // apply bfs
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        tm = max(t, tm);

        q.pop();

        // check for neighbours
        for (int i = 0; i < 4; ++i)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                visited[nrow][ncol] = 2;
                q.push({{nrow, ncol}, t + 1});
                count++;
            }
        }
    }

    if (freshCount != count)
        return -1;
    return tm;
}
int main()
{

    // Test case 1
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid1) << endl; // Expected Output: 4

    // Test case 2
    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << orangesRotting(grid2) << endl; // Expected Output: -1

    return 0;
}
