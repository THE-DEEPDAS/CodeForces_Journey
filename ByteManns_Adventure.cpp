#pragma GCC optimize("O2")
#include<bits/stdc++.h>
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
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        ll ans = 1,r = 1;
        for (ll i = 1; i < n; i++){
            if(a[i] - 1 == a[i - 1] || a[i] + 1 == a[i - 1] || a[i] == a[i - 1]){
                r++;
                ans = max(ans, r);
            }
            else{
                r = 1;
            }
        }
        cout << ans << endl;
    }
}