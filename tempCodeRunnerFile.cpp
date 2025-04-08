#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
bool found = false;

// DFS to find path from start to end
void findPath(int curr, int end, vector<int> &currPath)
{
    if (found)
        return;
    visited[curr] = true;
    currPath.push_back(curr);

    if (curr == end)
    {
        path = currPath;
        found = true;
        return;
    }

    for (int next : adj[curr])
    {
        if (!visited[next])
        {
            findPath(next, end, currPath);
        }
    }

    if (!found)
        currPath.pop_back();
}

void solve()
{
    int n, st, en;
    cin >> n >> st >> en;
    --st;
    --en; // Convert to 0-based indexing

    // Initialize graph
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    path.clear();
    found = false;

    // Read tree edges
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v; // Convert to 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find path from st to en
    vector<int> currPath;
    findPath(st, en, currPath);

    // Construct permutation
    vector<int> p;

    // First add intermediate vertices from path (excluding start)
    for (int i = 1; i < path.size(); i++)
    {
        p.push_back(path[i] + 1); // Convert back to 1-based indexing
    }

    // Fill remaining positions with end vertex
    while (p.size() < n)
    {
        p.push_back(en + 1); // Convert back to 1-based indexing
    }

    // Print permutation
    for (int i = 0; i < n; i++)
    {
