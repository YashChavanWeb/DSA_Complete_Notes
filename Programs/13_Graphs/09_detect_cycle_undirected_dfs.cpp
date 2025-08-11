#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int visited[], vector<int> adj[])
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            // dfs(it, node, visited, adj) ;  // this is returning true or false
            if (dfs(it, node, visited, adj))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            // then how did it mark itself ??? - because it was previously in the path !!!
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<vector<int>> &edges)
{

    int n = edges.size();

    // convert to adj list
    vector<int> adj[V];
    for (int i = 0; i < n; ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // start with the dfs process
    int visited[V] = {0};

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, visited, adj))
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
