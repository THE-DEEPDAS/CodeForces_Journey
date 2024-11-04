#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// An important note that if you will use unordered map your solution will not pass all the testcases
// so in competitve programming never prefer unordered mp over the normal map
// my solution got hacked and i just changed to map and it got accepted :D

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

int main() {
    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<ll, ll> prefix_sum_map;
        ll prefix_sum = 0, beautiful_segments = 0;
        prefix_sum_map[0] = 1;

        for (ll i = 0; i < n; i++) {
            prefix_sum += a[i];
            if (prefix_sum_map[prefix_sum]) {
                beautiful_segments++;
                prefix_sum_map.clear();
                prefix_sum_map[0] = 1;
                prefix_sum = 0;
            } 
            else {
                prefix_sum_map[prefix_sum]++;
            }
        }

        cout << beautiful_segments << "\n";
    }
}