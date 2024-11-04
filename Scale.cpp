// n * n grid with 0's or 1's
// split it into k * k blocks
// replace it with one element which is same for all the grid elements
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to reduce the grid by factor k
vector<string> reduceGrid(ll n, ll k, const vector<string>& grid) {
    vector<string> reducedGrid;

    for (ll i = 0; i < n; i += k) {
        string row;
        for (ll j = 0; j < n; j += k) {
            row += grid[i][j];
        }
        reducedGrid.push_back(row);
    }

    return reducedGrid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the number of test cases

    while (t--) {
        ll n, k;
        cin >> n >> k;
        cin.ignore(); // Ignore the newline character after reading n and k

        vector<string> grid(n);
        for (ll i = 0; i < n; ++i) {
            getline(cin, grid[i]);
        }

        vector<string> reducedGrid = reduceGrid(n, k, grid);

        for (const string& row : reducedGrid) {
            cout << row << endl;
        }
    }
    return 0;
}
