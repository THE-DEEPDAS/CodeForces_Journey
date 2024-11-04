// Shows Time Limit Exceeded :(
#include <iostream>
using namespace std;
typedef long long ll;

inline ll xor_upto(ll x) {
    if (x % 4 == 0) return x;
    else if (x % 4 == 1) return 1;
    else if (x % 4 == 2) return x + 1;
    else return 0;
}

inline ll xor_range(ll l, ll r) {
    return xor_upto(r) ^ xor_upto(l - 1);
}

ll xor_sequence(ll start, ll step, ll count) {
    ll result = 0;
    for (ll i = 0; i < count; i++) {
        result ^= (start + i * step);
    }
    return result;
}

ll interesting_xor(ll l, ll r, ll i, ll k) {
    ll mod_val = 1LL << i; 
    ll start = l + (k - l % mod_val + mod_val) % mod_val;
    if (start > r) return xor_range(l, r);
    ll count = (r - start) / mod_val + 1;
    ll full_xor = xor_range(l, r);
    ll uninteresting_xor = xor_sequence(start, mod_val, count);

    return full_xor ^ uninteresting_xor;
}

int main() {
    ll testcases;
    cin >> testcases;
    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll l, r, i, k;
        cin >> l >> r >> i >> k;
        cout << interesting_xor(l, r, i, k) << "\n";
    }
}
