#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        ll special_index = -1;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 1 && a[i] != -1) {
                special_index = i; // Locate the special element
            }
        }

        set<ll> unique_sums;
        unique_sums.insert(0); // Include the sum of the empty subarray

        if (special_index == -1) {
            // Case 1: No special element
            ll curr_sum = 0;
            for (ll x : a) {
                curr_sum += x;
                unique_sums.insert(curr_sum); // Add cumulative sums
            }
        } else {
            // Case 2: Special element exists
            ll special_value = a[special_index];

            // Calculate prefix sums
            vector<ll> prefix_sums = {0};
            ll curr_sum = 0;
            for (ll i = 0; i < special_index; i++) {
                curr_sum += a[i];
                prefix_sums.push_back(curr_sum);
            }

            // Calculate suffix sums
            vector<ll> suffix_sums = {0};
            curr_sum = 0;
            for (ll i = n - 1; i > special_index; i--) {
                curr_sum += a[i];
                suffix_sums.push_back(curr_sum);
            }

            // Merge prefix, suffix, and special value into unique sums
            for (ll prefix : prefix_sums) {
                unique_sums.insert(prefix);
                unique_sums.insert(prefix + special_value);
                for (ll suffix : suffix_sums) {
                    unique_sums.insert(prefix + suffix);
                    unique_sums.insert(prefix + suffix + special_value);
                }
            }

            // Add suffix sums alone
            for (ll suffix : suffix_sums) {
                unique_sums.insert(suffix);
                unique_sums.insert(special_value + suffix);
            }

            // Include the special element as its own subarray
            unique_sums.insert(special_value);
        }

        // Output results
        cout << unique_sums.size() << "\n";
        for (ll sum : unique_sums) {
            cout << sum << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
