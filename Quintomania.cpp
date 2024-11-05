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
    ll t;
    cin >> t;

    for (ll testcase = 0; testcase < t; testcase++) {
        ll n;
        cin >> n;

        vector<ll> melody(n);
        for (ll i = 0; i < n; i++) {
            cin >> melody[i];
        }

        bool isPerfect = true;
        for (ll i = 1; i < n; i++) {
            ll interval = abs(melody[i] - melody[i - 1]);
            if (interval != 5 && interval != 7) {
                isPerfect = false;
                break;
            }
        }

        cout << (isPerfect ? "YES" : "NO") << '\n';
    }
}