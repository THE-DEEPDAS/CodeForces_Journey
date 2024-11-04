// we have an array of numbers
// we have an array of permutation(p)
// we have an array of chars with 'L' and "R"
// find if we can sort the permutation by changing adjacents in any number of moves
// so logic is we can if min number in R > max number corresponding to L
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canSortPermutation(const vector<ll>& numbers, const vector<ll>& permutation, const string& s) {
    ll maxL = LLONG_MIN; // Maximum number corresponding to 'L'
    ll minR = LLONG_MAX; // Minimum number corresponding to 'R'

    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            maxL = max(maxL, numbers[permutation[i]]);
        } else if (s[i] == 'R') {
            minR = min(minR, numbers[permutation[i]]);
        }
    }

    // Check if the condition is satisfied
    return minR > maxL; // We can sort if min in R > max in L
}

int main() {
    ll t; // Number of test cases
    cin >> t;

    while (t--) {
        ll n, q; // Length of the permutation and number of queries
        cin >> n >> q;

        vector<ll> permutation(n); // Array of permutation
        for (ll i = 0; i < n; i++) {
            cin >> permutation[i]; // Input permutation
        }

        string directions; // Array of directions
        cin >> directions; // Input directions

        // Process each query
        for (ll j = 0; j < q; j++) {
            ll index; // Index to change
            cin >> index;
            // Change the direction at the specified index
            directions[index - 1] = (directions[index - 1] == 'L') ? 'R' : 'L';

            // Output result based on the sorting condition after each query
            if (canSortPermutation(permutation, permutation, directions)) {
                cout << "YES" << endl; // Can sort the permutation
            } else {
                cout << "NO" << endl; // Cannot sort the permutation
            }
        }
    }

    return 0;
}
