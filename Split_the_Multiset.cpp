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

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n, k;
        cin >> n >> k;

        ll ans = 0; 
        while (n > 1) {
            if (n <= k) {
                ans++;
                break;
            }
            else {
                // Otherwise, break n into as close to equal parts as possible
                ll quotient = n / k; // Maximum parts we can divide into
                ll remainder = n % k; // Remaining part after division
                
                if (remainder == 0) {
                    ans += 1;
                }
                else {
                    ans += 2;
                }
                n = quotient;
            }
        }

        cout << ans << endl;
    }

}
