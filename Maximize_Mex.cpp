#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr); // Untie cin and cout for faster input/output
    }
} fast_io_setup; // This will be executed before main()

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n, x;
        cin >> n >> x;
        vector<ll> elements(n);
        map<ll, ll> frequency;

        // Populate the frequency map with each element's count
        for (ll i = 0; i < n; i++) {
            cin >> elements[i];
            frequency[elements[i]]++;
        }

        ll missing_mex = 0; // Track the minimum missing integer
        for (auto &entry : frequency) {
            ll element_value = entry.first;
            ll element_count = entry.second;

            // Check if the current missing_mex is present
            if (missing_mex != element_value) {
                cout << missing_mex << endl;
                break;
            }

            // Move to the next missing integer if present
            missing_mex++;

            // Shift excess counts to element + x
            if (element_count > 1) {
                frequency[element_value + x] += element_count - 1;
            }
        }
        
        // Output the final MEX if loop completes without break
        if (missing_mex == frequency.rbegin()->first + 1) {
            cout << missing_mex << endl;
        }
    }
}
