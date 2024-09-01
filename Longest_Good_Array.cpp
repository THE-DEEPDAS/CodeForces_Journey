// an array is good if all elements are such that a(i - 1) < ai
// also difference between elements should gradually increase
// in range L to R , what is max length good array
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// so l + n(n - 1) / 2 <= r

bool possible(ll l, ll r, ll n) {
    return l + (n * (n - 1)) / 2 <= r;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll l, r;
        cin >> l >> r;

        ll low = 1, high = 1e9;

        while (low <= high) {
            ll mid = (low + high) / 2;
            if (possible(l, r, mid)){
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }

        cout << high << endl; // as max is ans
    }
}
