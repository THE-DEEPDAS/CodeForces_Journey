// in a permutation index j is reachable if we can reach there by i = p[i]
// black = 0, white = 1
// find number of blacks reachable from current index
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
// so black are defined by 0 so we need to check how many index we can reach 
// which have the value 0
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> p(n);
        for (ll i = 0; i < n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;

        vector<ll> result(n);
        vector<bool> visited(n, false);
        vector<ll> black_count_in_cycle(n, 0);

        for (ll i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<ll> cycle;
                ll current = i;
                while (!visited[current]) {
                    visited[current] = true;
                    cycle.push_back(current);
                    current = p[current] - 1; // move to the next element
                }

                ll black_count = 0;
                for (ll node : cycle) {
                    if (s[node] == '0') {
                        black_count++;
                    }
                }

                // if one node is reachable and is part of a cycle then all nodes 
                // which are reachable are of same cycle
                for (ll node : cycle) {
                    black_count_in_cycle[node] = black_count;
                }
            }
        }

        for (ll num : black_count_in_cycle) {
            cout << num << " ";
        }
        cout << endl;
    }
}
