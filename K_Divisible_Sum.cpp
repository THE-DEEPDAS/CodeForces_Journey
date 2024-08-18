// we have 2 integers n and k
// create an array with minimum possible max element such that sum of elements in array is divisible by k of n integers
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main() {
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n, k;
        cin >> n >> k;

        if (n == 1) {
            // if there is only one element, it must be k.
            cout << k << endl;
        } 
        else if (n % k == 0) {
            // if n is divisible by k, we need only one element (n/k) repeated k times.
            cout << 1 << endl;
        } 
        else if (n > k) {
            // more slots available so 1 and 2 will make up for the space that is extra
            cout << 2 << endl;
        } 
        else {
            // if n is less than k, we find the smallest multiplier x so that x * n >= k.
            ll ans = (k + n - 1) / n;
            cout << ans << endl;
        }
    }
}