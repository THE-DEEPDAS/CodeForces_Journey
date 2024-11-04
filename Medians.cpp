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
        ll n, k;
        cin >> n >> k;

        if(k == (n + 1) / 2){
            cout << n << endl;
            for (ll i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            if(k == 1 || k == n)
                cout << -1 << endl;
            else if((2 * k - 1 < n)){
                cout << 3 << endl;
                cout << 1 << " " << 2 << " " << 2 * k - 1 << endl;
            }
            else{
                // vacche = n - k - 1 elements aave
                cout << 3 << endl;
                cout << 1 << " " << k - (n - k - 1) << " " << n << endl;
            }
        }
    }
}