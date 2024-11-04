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
    ll n;
    cin >> n;
    vector<ll> num(n);
    for (ll i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<ll> pre(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + num[i];
    }

    ll sz = n * (n + 1) / 2;
    vector<ll> sums(sz + 1, 0);
    ll idx = 1;
    for (ll l = 0; l < n; l++) {
        for (ll r = l; r < n; r++) {
            sums[idx] = sums[idx - 1] + (pre[r + 1] - pre[l]);
            idx++;
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << sums[r] - sums[l - 1] << "\n";
    }
}
