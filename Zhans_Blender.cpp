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

    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;

        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }

        ll blend_per_second = min(x, y);

        ll seconds = (n + blend_per_second - 1) / blend_per_second;

        cout << seconds << '\n';
    }
}
