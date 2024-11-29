#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> constraints(k);
    for (auto &x : constraints) {
        cin >> x.first >> x.second;
        x.first--;  // Convert to 0-based index
        x.second--;
    }
    sort(constraints.begin(), constraints.end());

    set<pair<int, int>> active_constraints;
    pair<int, int> mn = {INT_MAX, INT_MAX}, mx = {-INT_MAX, -INT_MAX};

    for (int i = 0, idx = 0; i + d - 1 < n; i++) {
        while (idx < k && constraints[idx].first <= i + d - 1) {
            active_constraints.insert({constraints[idx].second, idx});
            idx++;
        }
        while (!active_constraints.empty() && active_constraints.begin()->first < i) {
            active_constraints.erase(active_constraints.begin());
        }

        int count = active_constraints.size();
        mn = min(mn, {count, i});
        mx = max(mx, {count, -i});
    }

    cout << -mx.second + 1 << " " << mn.second + 1 << "\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
