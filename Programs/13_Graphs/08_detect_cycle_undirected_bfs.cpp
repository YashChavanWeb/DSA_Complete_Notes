#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int V, vector<int> adj[], int visited[])
{
    queue<pair<int, int>> q;

    visited[0] = 1;
    q.push({0, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (visited[it] && it != parent)
            {
                // this is not possible , so it means someone else just came and did it
                return true;
            }
            else if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<vector<int>> &edges)
{

    // convert the matrix to adjacency list
    vector<int> adj[V];

    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int visited[V] = {0};

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            if (detectCycle(V, adj, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    int V1 = 7;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 2} // Edge (5, 2) creates a cycle
    };

    cout << "Graph 1 (With Cycle): ";
    if (isCycle(V1, edges1))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected!" << endl;
    }

    int V2 = 8;
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7} // No cycle here
    };

    cout << "Graph 2 (Without Cycle): ";
    if (isCycle(V2, edges2))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected!" << endl;
    }

    return 0;
}
