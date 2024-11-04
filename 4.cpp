#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<vector<int>> a(n, vector<int>(k));
    vector<vector<int>> b(n, vector<int>(k));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }

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
        vector<pair<int, pair<char, int>>> r(m);
        
        for (int i = 0; i < m; ++i) {
            cin >> r[i].first >> r[i].second.first >> r[i].second.second;
        }

        int res = -1;

        for (int i = 0; i < n; ++i) {
            bool valid = true;
            for (const auto& req : r) {
                int idx = req.first - 1;
                char op = req.second.first;
                int val = req.second.second;

                if ((op == '<' && b[i][idx] >= val) || (op == '>' && b[i][idx] <= val)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res = res == -1 ? i + 1 : min(res, i + 1);
            }
        }
        cout << res << endl; 
    }
}
