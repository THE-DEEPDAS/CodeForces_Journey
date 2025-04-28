#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        
        // Check if we can already satisfy all requirements
        int satisfied = 0;
        for (int i = 0; i < n && satisfied < m; i++) {
            if (a[i] >= b[satisfied]) satisfied++;
        }
        
        if (satisfied == m) {
            cout << 0 << "\n";
            continue;
        }
        
        // We need to add one flower
        ll ans = LLONG_MAX;
        
        // For each possible prefix of matched requirements:
        // 0 to satisfied (inclusive)
        for (int prefix = 0; prefix <= satisfied; prefix++) {
            // Add flower after matching 'prefix' requirements
            // This flower needs beauty >= b[prefix]
            ll k = b[prefix];
            
            // Check if the remaining (satisfied - prefix) matches plus the new flower (1)
            // can satisfy enough remaining requirements
            int remaining_needed = m - prefix - 1;
            int available_matches = satisfied - prefix;
            
            if (available_matches >= remaining_needed) {
                ans = min(ans, k);
            }
        }
        
        if (ans == LLONG_MAX) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    
    return 0;
}