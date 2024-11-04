#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup; // This will be executed before main()

// Function to calculate the current disturbance
ll calculate_disturbance(const vector<ll>& a) {
    ll disturbance = 0;
    for (ll i = 0; i < a.size() - 1; ++i) {
        if (a[i] == a[i + 1]) {
            disturbance++;
        }
    }
    return disturbance;
}

int main() {
    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (ll i = 1; i < n / 2; i++) {  
            if(a[i] == a[i - 1])
                swap(a[i], a[n - i - 1]);
            if(a[n - i] == a[n - i - 1])
            swap(a[i], a[n - i - 1]);
        }
        ll min_disturbance = calculate_disturbance(a);
        cout << min_disturbance << '\n';
    }
}