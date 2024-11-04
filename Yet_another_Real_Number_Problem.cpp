#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

bool comp(ll lastVal, ll currentVal, ll count) {
    if (count > 30) return true;
    return lastVal < currentVal * (1LL << count);
}

int main() {
    ll testcases;
    cin >> testcases;
    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<ll, ll>> st;
        ll result = 0;
        vector<ll> powerOfTwo(n * 32 + 1);
        powerOfTwo[0] = 1;

        for (ll i = 1; i <= n * 32; i++) {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
        }

        for (ll i = 0; i < n; i++) {
            ll currentValue = a[i];
            ll count = 0;

            while (currentValue % 2 == 0) {
                currentValue /= 2;
                count++;
            }

            while (!st.empty() && comp(st.back().first, currentValue, count)) {
                result = (result - st.back().first * powerOfTwo[st.back().second] % MOD + MOD) % MOD;
                result = (result + st.back().first) % MOD;
                count += st.back().second;
                st.pop_back();
            }

            st.push_back({currentValue, count});
            result = (result + st.back().first * powerOfTwo[st.back().second]) % MOD;
            cout << result << (i < n - 1 ? " " : "\n");
        }
    }
}
