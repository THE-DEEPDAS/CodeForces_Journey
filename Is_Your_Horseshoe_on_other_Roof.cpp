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
    // we just need to find the repeating numbers
    set<ll> s;
    for (int i = 0; i < 4; i++){
        ll x;
        cin >> x;
        s.insert(x);
    }

    cout << 4 - s.size();
}