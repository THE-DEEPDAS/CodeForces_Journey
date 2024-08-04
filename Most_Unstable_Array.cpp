// we have n and m and our task is to create an array whose sum of elements is m of n elements and
// condition is we want |ai - a(i+1)| is maximum
// all elements >= 0
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

ll max_abs_diff(ll n, ll m) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return m;
    } else {
        // number of non-zero elements in odd positions
        ll k = (n) / 2;
        
        // max value for these positions
        ll max_value = m / k;
        
        // calculate the total difference
        ll total_diff = 2 * max_value * (k);
        
        // adjust for the remainder to ensure the sum is exactly m
        ll remainder = m % k;
        total_diff += (2 * remainder);
 
        return total_diff;
    }
}
 
int main() {
    ll testcases;
    cin >> testcases;
 
    while (testcases--) {
        ll n, m;
        cin >> n >> m;
        cout << max_abs_diff(n, m) << endl;
    }
 
}