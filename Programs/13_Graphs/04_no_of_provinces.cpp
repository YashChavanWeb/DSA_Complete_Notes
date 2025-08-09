#include <bits/stdc++.h>
using namespace std;

void bfs(int node, int visited[], vector<int> adj[])
{
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}

int noOfProvinces(vector<vector<int>> &isConnected)
{

    // convert to adj list
    int n = isConnected.size();
    vector<int> adj[n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int count = 0;
    int visited[n] = {0};
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            count++;
            bfs(i, visited, adj);
        }
    }

    return count;
}

int main()
{

    vector<vector<int>> isConnected1 = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}};
    cout << "Number of provinces in isConnected1: " << noOfProvinces(isConnected1) << endl;

    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    cout << "Number of provinces in isConnected2: " << noOfProvinces(isConnected2);

    return 0;
}