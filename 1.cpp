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
        ll n, m, r1, r2;
        cin >> n >> m >> r1 >> r2;
        if(r2 < r1)
            swap(r1, r2);
        ll ans = r1 + 1;
        ans *= 2;
        if(r1 + 1 + r1 )
        }
}