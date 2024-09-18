// we need to take 2 indexes i and j and ai , aj should have different parity
// if ai < aj then replace ai with ai + aj
// else replace aj with ai + aj
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n;
        cin >> n;

        vector<pair<ll, ll>> evens;
        vector<pair<ll, ll>> odds;
        vector<ll> ans(n, 0);

        ll temp;
        for (ll i = 0; i < n; i++) {
            cin >> temp;
            if (temp & 1)
                odds.push_back(make_pair(temp, i));
            else
                evens.push_back(make_pair(temp, i));
        }

        if (odds.size() == 0 || evens.size() == 0) {
            cout << 0 << endl;
        } else {
            bool replaced = false;
            for (auto& odd : odds) {
                for (auto& even : evens) {
                    if (odd.first < even.first) {
                        ans[odd.second] = odd.first + even.first;
                        replaced = true;
                    } else {
                        ans[even.second] = odd.first + even.first;
                        replaced = true;
                    }
                    // Break after replacing once to avoid multiple replacements
                    break;
                }
                if (replaced) {
                    break;
                }
            }
            
            // Print the result for this test case
            for (ll i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}
