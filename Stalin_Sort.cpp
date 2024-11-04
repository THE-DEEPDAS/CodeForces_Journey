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
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        ll result = INT_MAX;
        for (ll i = 0; i < n; i++){
            ll current_ans = i;
            for (ll j = i + 1; j < n; j++){
                if(a[j] > a[i])
                    current_ans++;
            }
            result = min(result, current_ans);
        }

        cout << result << endl;
    }
}
