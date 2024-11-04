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

bool canPaintWithK(vector<ll>& a, ll limit) {
    ll length = a.size();
    vector<bool> dpA(length + 1, false);
    vector<bool> dpB(length + 1, false);
    dpA[0] = true;
    dpB[0] = false;

    for (ll i = 0; i < length; i++) {
        vector<bool> nextA(length + 1, false);
        vector<bool> nextB(length + 1, false);

        if (dpA[i]) {
            if (i + 1 < length && abs(a[i + 1] - a[i]) <= limit) {
                nextA[i + 2] = true;
            }
            if (limit >= 1) {
                nextB[i + 1] = true;
            }
        }

        if (dpB[i]) {
            if (i + 1 < length && abs(a[i + 1] - a[i]) <= limit) {
                nextB[i + 2] = true;
            }
        }

        for (ll j = 0; j <= length; j++) {
            if (nextA[j]) dpA[j] = true;
            if (nextB[j]) dpB[j] = true;
        }
    }

    return dpA[length] || dpB[length];
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll left = 0, right = 1e18, result = right;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (canPaintWithK(a, mid)) {
                result = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }

        cout << result << endl;
    }
}
