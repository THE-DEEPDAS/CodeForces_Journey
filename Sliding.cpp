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

    while(t--){
        ll rows, cols, i, j;
        cin >> rows >> cols >> i >> j;
        // jo same row ma baki na elelments 1 move thay ane next row mathi ek element evo hoy je (columns - 1) move thay

        ll ans = (2 * cols - 1) * (rows - i) + cols - j;
        cout << ans << endl;
    }
}