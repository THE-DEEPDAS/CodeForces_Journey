#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

// inverse of mod is using fermet's little theorem
ll mod_inverse(ll x, ll mod) {
    ll result = 1;
    ll exp = mod - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        vector<ll> values(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> values[i];
            sum = (sum + values[i]) % MOD;
        }

        ll total_sum_of_products = 0;
        for (ll i = 0; i < n; i++) {
            // so we remove the value[i] so it gets muliplied with all j such that j != i
            total_sum_of_products = (total_sum_of_products + values[i] * (sum - values[i])) % MOD;
        }
        total_sum_of_products = (total_sum_of_products * mod_inverse(2, MOD)) % MOD;

        ll total_pairs = (n * (n - 1)) / 2;
        ll total_pairs_inv = mod_inverse(total_pairs, MOD);

        ll result = (total_sum_of_products * total_pairs_inv) % MOD;
        cout << result << endl;
    }
}
