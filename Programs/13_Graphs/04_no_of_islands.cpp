#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, int>> q;
    visited[row][col] = 1;
    q.push({row, col});

    int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 8; ++i) {
            int nRow = r + dRow[i];
            int nCol = c + dCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !visited[nRow][nCol]) {
                visited[nRow][nCol] = 1;
                q.push({nRow, nCol});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!visited[i][j] && grid[i][j] == '1') {
                count++;
                bfs(i, j, grid, visited);
            }
        }
    }
    return count;
}

int main() {
    // Example usage
    vector<vector<char>> grid1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '1', '0'},
        {'0', '1', '0', '0', '1'}
    };

    cout << "Number of islands in grid 1: " << numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {
        {'1', '1', '1'},
        {'0', '0', '0'},
        {'0', '0', '1'}
    };

    cout << "Number of islands in grid 2: " << numIslands(grid2) << endl;

    return 0;
}