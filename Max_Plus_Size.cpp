#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll odd_sum = 0, even_sum = 0;
        ll max_odd = LLONG_MIN; 
        ll max_even = LLONG_MIN;
        for (ll i = 0; i < n; i++) {
            ll num;
            cin >> num;

            if (i & 1) { 
                odd_sum += num;
                max_odd = max(max_odd, num);
                
            } 
            else { 
                even_sum += num;
                max_even = max(max_even, num);
            }
        }

        ll odds = (n + 1) / 2;  
        ll evens = n / 2;       

        ll result = max_odd + evens; 
        result = max(result, max_even + odds); 

        cout << result << endl;
    }
}
