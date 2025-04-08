#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Find path between two vertices using BFS
vector<int> find_path(const vector<vector<int>> &adj, int start, int end)
{
    int n = adj.size();
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(start);
    parent[start] = start;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == end)
            break;

        for (int next : adj[curr])
        {
            if (parent[next] == -1)
            {
                parent[next] = curr;
                q.push(next);
            }
        }
    }

    // Reconstruct path
    vector<int> path;
    for (int v = end; v != start; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void solve()
{
    int n, st, en;
    cin >> n >> st >> en;

    // If start and end are same, just output it once
    if (st == en)
    {
        cout << st << "\n";
        return;
    }

    --st;
    --en; // Convert to 0-based indexing

    // Read tree edges
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v; // Convert to 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find path from start to end
    vector<int> path = find_path(adj, st, en);

    // Construct permutation
    vector<int> p;

    // First add the path vertices (except start)
    for (int vertex : path)
    {
        p.push_back(vertex + 1); // Convert back to 1-based indexing
    }

    // Fill remaining positions with end vertex
    while (p.size() < n)
    {
        p.push_back(en + 1); // Convert back to 1-based indexing
    }

    // Print result
    for (int x : p)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
