#include <bits/stdc++.h>
using namespace std;

/*

Time complexity:
Undirected graph: O(N) + O(2E)


Space complexity -> O(N) + O(N) + O(N) = O(3N)

*/

void dfs(int node, int visited[], vector<int> adj[], vector<int> &ls)
{
    // mark the mode
    visited[node] = 1;
    ls.push_back(node);

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj, ls);
        }
    }
}

vector<int> dfsTraverse(int V, vector<int> adj[])
{
    // data structures
    vector<int> ls;
    int visited[V + 1] = {0};
    int start = 1;

    dfs(start, visited, adj, ls);

    return ls;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs = dfsTraverse(n, adj);

    for (int b : bfs)
    {
        cout << b << " ";
    }
    cout << endl;

    return 0;
}
