#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maximize_mex(vector<ll> &a, ll x) {
    unordered_set<ll> unique_elements; // For fast access
    queue<ll> repeating; // To handle repeated elements
    ll mex = 0;

    // Insert elements into the set and identify repetitions
    for (ll num : a) {
        if (unique_elements.find(num) != unique_elements.end()) {
            repeating.push(num); // Push to queue if repeated
        } else {
            unique_elements.insert(num);
            // Update MEX while possible
            while (unique_elements.find(mex) != unique_elements.end()) {
                mex++;
            }
        }
    }

    // Process repeating elements
    while (!repeating.empty()) {
        ll current = repeating.front();
        repeating.pop();

        ll new_value = current + x; // Add x to the current repeated element
        if (unique_elements.find(new_value) == unique_elements.end()) {
            unique_elements.insert(new_value); // Add to unique set
            // Update MEX while possible
            while (unique_elements.find(mex) != unique_elements.end()) {
                mex++;
            }
        } else {
            // If new_value already exists, push it back to the queue
            repeating.push(new_value);
        }
    }

    return mex;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll testcases;
    cin >> testcases;
    while (testcases--) {
        ll n, x;
        cin >> n >> x;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << maximize_mex(a, x) << endl;
    }
}
