// we have 2 arrays we need to find that if it is possible to take k numbers from both such that k/2 elements from
// each array are choosen and it covers all elements from 1 to k
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, m, k;
        cin >> n >> m >> k;

        vector<ll> a(n), b(m);
        set<ll> set_a, set_b;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] <= k) {
                set_a.insert(a[i]);
            }
        }
        for (ll i = 0; i < m; i++) {
            cin >> b[i];
            if (b[i] <= k) {
                set_b.insert(b[i]);
            }
        }

        // Count how many numbers from 1 to k are covered
        ll total_covered = 0;
        for (ll i = 1; i <= k; i++) {
            if (set_a.count(i) > 0 || set_b.count(i) > 0) {
                total_covered++;
            }
        }

        // Check if we can select exactly k/2 from each array
        ll covered_from_a = min((k / 2), (ll)set_a.size());
        ll covered_from_b = min((k / 2), (ll)set_b.size());

        if (covered_from_b == k / 2 && covered_from_a == k / 2 && total_covered == k) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
}
