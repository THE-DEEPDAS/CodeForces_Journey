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

        ll ones = 0, z = 0;
        vector<ll> a(2*n);
        for (ll i = 0; i <2* n; i++)
            {
                cin >> a[i];
                if(a[i] == 1)
                    ones++;
                else
                    z++;
            }
            ll mini = ones % 2 == 0 ? 0 : 1;
            cout << mini << " " << min(z, ones) << endl;
    }
}