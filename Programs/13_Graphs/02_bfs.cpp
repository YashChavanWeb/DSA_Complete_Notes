#include <bits/stdc++.h>
using namespace std;

/*

Time Complexity:
- first is the outer while loop -> it will run for all nodes so O(N)
- then is the inner for loop -> it will be running for all its degrees / neighbors, and we know that it will run for total degrees which is O(2*E)

- So overall complexity will be O(N) + O(2E)


*/

vector<int> bfsTraverse(int V, vector<int> adj[])
{

    // data structures
    int visited[V] = {0};
    queue<int> q;
    vector<int> bfs;

    visited[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs = bfsTraverse(n, adj);

    for (int b : bfs)
    {
        cout << b << " ";
    }
    cout << endl;

    return 0;
}
