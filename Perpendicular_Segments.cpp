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
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll x, y, k;
        cin >> x >> y >> k;

        ll mini = min(x, y);

        cout << 0 << " " << mini << " " << mini << " " << 0 << endl;
        cout << 0 << " " << 0 << " " << mini << " " << mini << endl;
    }
}