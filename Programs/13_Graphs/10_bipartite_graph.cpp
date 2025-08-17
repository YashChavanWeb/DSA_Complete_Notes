#include <bits/stdc++.h>
using namespace std;

/*
// If a graph can be colored with 2 colors, having no same color in the adjacent then it is called Bipartite Graph


// Odd Cycle - cannot be bipartite
// even cycle - bipartite graph
// linear graph - bipartite graph

*/

bool dfs(int node, int color, int visited[], vector<int> adj[])
{
    visited[node] = color;

    for (auto it : adj[node])
    {
        if (visited[it] == -1)
        {
            if (dfs(it, !color, visited, adj) == false)
            {
                return false;
            }
        }
        else if (visited[it] == color)
        {
            // if previously then its color should be diff than adj
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    int m = graph[0].size();

    // convert to adj list
    vector<int> adj[n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (graph[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // visited
    int visited[n];
    for (int i = 0; i < n; ++i)
        visited[i] = -1;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == -1)
        {
            if (dfs(i, 0, visited, adj) == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};

    if (isBipartite(graph))
        cout << "The graph is bipartite." << endl;
    else
        cout << "The graph is not bipartite." << endl;

    return 0;
}