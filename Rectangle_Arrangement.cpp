// we need to colour an infinite grid and each cell is currently white in beginning
// each stamp used for coluring is of height hi and widht wi
// a stamp can only be used once and stamp should cover the cell fully if used on it
// we can overlap the stamps if needed
// 
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
        ll n;
        cin >> n;

        vector<ll> width(n);
        vector<ll> height(n);
        ll max_width = 1, max_height = 1;
        for (ll i = 0; i < n; i++){
            cin >> width[i] >> height[i];
            max_width = max(max_width, width[i]);
            max_height = max(max_height, height[i]);
        }

        cout << 2 * (max_height + max_width) << endl;
    }
}