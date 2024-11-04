#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    
    while (t--) {
        ll n, r;
        cin >> n >> r;
        
        vector<ll> a(n);
        ll ans = 0;
        ll left = 0;
        ll used = 0;

        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            ans += (a[i] / 2) * 2; // Count pairs
            used += a[i] / 2;      // Total pairs used
            if (a[i] % 2 == 1) {
                left++; // Count singles
            }
        }

        ll possible = r - used; // Calculate available rows
        if (possible >= left) {
            ans += left; // All singles can be seated in remaining rows
        } 
        else {
            //if possible = 3 and left = 4 so 2,1,1
            // pos = 5 left = 7 then 1,1,1,2,2
            ans += possible - (left - possible); // Seat as many singles as possible
        }

        cout << ans << '\n'; // Output the total happy people
    }
}