#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

bool hasPattern(const string &s, ll idx) {
    return idx >= 0 && idx + 3 < s.size() && s[idx] == '1' && s[idx + 1] == '1' && s[idx + 2] == '0' && s[idx + 3] == '0';
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll q;
        cin >> q;

        set<ll> pattern_indices;
        for (ll i = 0; i <= (ll)s.length() - 4; i++) {
            if (hasPattern(s, i)) {
                pattern_indices.insert(i);
            }
        }

        while(q--) {
            ll i, v;
            cin >> i >> v;
            i--;  
            
            for (ll j = i - 3; j <= i; j++) {
                if (hasPattern(s, j)) {
                    pattern_indices.erase(j);
                }
            }

            s[i] = v + '0';

            for (ll j = i - 3; j <= i; j++) {
                if (hasPattern(s, j)) {
                    pattern_indices.insert(j);
                }
            }

            cout << (pattern_indices.empty() ? "NO\n" : "YES\n");
        }
    }
}
