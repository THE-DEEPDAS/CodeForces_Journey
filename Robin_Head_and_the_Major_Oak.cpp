#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll odd_count = 0;
        for (ll i = n - k + 1; i <= n; i++) {
            if (i % 2 == 1) { 
                odd_count++;
            }
        }

        if (odd_count % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
