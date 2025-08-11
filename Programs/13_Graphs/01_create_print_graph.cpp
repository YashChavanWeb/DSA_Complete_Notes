#include <bits/stdc++.h>
using namespace std;

/*

// Sum of adjacent edges = sum of degrees = 2*E 
for a undirected graph

*/

int main()
{

    int n, m; // nodes , edges
    cin >> n >> m;

    // adjacency list for graph
    vector<int> arr[n + 1]; // n - 0 based , n + 1 - 1 based

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        // this is for undirected, for directed only u --> v
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // printing a graph
    for (int i = 1; i < n; ++i)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < arr[i].size(); ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}