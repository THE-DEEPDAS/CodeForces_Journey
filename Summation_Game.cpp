// we have array of n elements
// first alice will remove atmost k elements 
// bob will multiply atmost x elements with -1, game ends here 
// alice = maximise, bob = minimise
// find the sum of elements if both play optimally
// also all elements are positives only
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n, k, x;
        cin >> n >> k >> x;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort array in descending order to easily access the largest elements
        sort(a.rbegin(), a.rend());

        // Prefix sums to quickly calculate sums of subsets of `a`
        vector<ll> prefixSum(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + a[i];
        }

        // Variable to store the maximum possible sum if both play optimally
        ll maxSum = LLONG_MIN;

        // Iterate over the number of elements Alice might remove (from 0 to k)
        for (ll i = 0; i <= k; i++) {
            // Alice removes `i` largest elements, leaving `n - i` elements
            ll remainingSum = prefixSum[n] - prefixSum[i];

            // Bob negates the `x` largest remaining elements, if possible
            ll toNegate = min(x, n - i);
            ll negateSum = prefixSum[i + toNegate] - prefixSum[i];

            // Calculate the resulting sum after negation
            ll currentSum = remainingSum - 2 * negateSum;

            // Update maxSum to get the maximum possible sum after optimal play
            maxSum = max(maxSum, currentSum);
        }

        cout << maxSum << "\n";
    }
}
