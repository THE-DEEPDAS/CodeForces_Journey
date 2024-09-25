// we are given an array and we need to input indexes such that in range l to r inclusive
// we will get a[l] != a[r]
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll testcases;
    cin >> testcases;
    
    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n;
        cin >> n;
        
        vector<ll> a(n + 1, 0); 
        
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        ll q;
        cin >> q;
        
        // Answering each query
        for (ll query = 0; query < q; query++) {
            ll left, right;
            cin >> left >> right;
            
            // First check boundary elements
            if (a[left] != a[right]) {
                cout << left << " " << right << "\n";
            } else {
                // If boundaries are the same, find any pair with different values inside the range
                bool found = false;
                for (ll i = left; i < right; i++) {
                    if (a[i] != a[i + 1]) {
                        cout << i << " " << (i + 1) << "\n";
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << -1 << " " << -1 << "\n";
                }
            }
        }
    }
}
