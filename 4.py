#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fast I/O setup
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<vector<int>> a(n, vector<int>(k));
    vector<vector<int>> b(n, vector<int>(k));

    // Input values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }

    // Precompute cumulative OR values
    for (int j = 0; j < k; ++j) {
        b[0][j] = a[0][j];
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            b[i][j] = b[i - 1][j] | a[i][j];
        }
    }

    while (q--) {
        int m;
        cin >> m;
        vector<pair<int, pair<char, int>>> req(m);
        
        for (int i = 0; i < m; ++i) {
            cin >> req[i].first >> req[i].second.first >> req[i].second.second;
        }

        int res = -1;

        // Check each country against the requirements
        for (int i = 0; i < n; ++i) {
            bool valid = true;
            for (const auto& r : req) {
                int idx = r.first - 1;  // Convert to 0-index
                char op = r.second.first;
                int val = r.second.second;
                
                // Check the conditions based on the operator
                if ((op == '<' && !(b[i][idx] < val)) || (op == '>' && !(b[i][idx] > val))) {
                    valid = false;
                    break;
                }
            }
            // If valid, update the result
            if (valid) {
                res = res == -1 ? i + 1 : min(res, i + 1);  // Store 1-based index
            }
        }
        cout << res << endl; 
    }

    return 0;
}
