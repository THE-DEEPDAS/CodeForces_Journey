// Shows Time limit exceeded :(
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr); // Untie cin and cout for faster input/output
    }
} fast_io_setup; // This will be executed before main()

int main() {
    ll n, k, q;
    cin >> n >> k >> q;
    
    vector<vector<ll>> values(n, vector<ll>(k));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) {
            cin >> values[i][j];
        }
    }
    vector<vector<ll>> precomputed_or(n, vector<ll>(k, 0));
    for (ll j = 0; j < k; j++) {
        ll current_or = 0;
        for (ll i = 0; i < n; i++) {
            current_or |= values[i][j];
            precomputed_or[i][j] = current_or;
        }
    }

    for (ll query = 0; query < q; query++) {
        ll m;
        cin >> m;
        vector<tuple<ll, char, ll>> requirements(m);
        for (ll i = 0; i < m; i++) {
            ll r, c;
            char op;
            cin >> r >> op >> c;
            requirements[i] = make_tuple(r - 1, op, c); 
        }

        ll result = -1;
        for (ll country = 0; country < n; country++) {
            bool satisfies_all = true;
            for (const auto& req : requirements) {
                ll r = get<0>(req);
                char op = get<1>(req);
                ll c = get<2>(req);
                ll value = precomputed_or[country][r];
                if ((op == '>' && value <= c) || (op == '<' && value >= c)) {
                    satisfies_all = false;
                    break;
                }
            }
            if (satisfies_all) {
                result = country + 1;
                break;
            }
        }
        cout << result << "\n";
    }
}
