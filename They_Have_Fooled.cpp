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
    vector<int> ans = {10, 10, 8, 9, 8, 7, 7, 7, 7, 0, 9, 6, 8};
    ll n;
    cin >> n;
    cout << ans[n % 13] << endl;
}