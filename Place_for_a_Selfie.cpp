#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

// Custom binary search function
// Searches for the first element greater than the given value
ll binary_search(const vector<ll>& slopes, ll target) {
    ll low = 0;
    ll high = slopes.size() - 1;
    ll result = -1; // Initialize result to an invalid value

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (slopes[mid] > target) {
            result = slopes[mid];
            high = mid - 1; // Continue searching in the left half
        } else {
            low = mid + 1; // Continue searching in the right half
        }
    }

    return result;
}

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

    while (testcases--) {
        ll n, m;
        cin >> n >> m;

        vector<ll> slopes(n);
        for (ll i = 0; i < n; i++) {
            cin >> slopes[i];
        }

        sort(slopes.begin(), slopes.end()); // Ensure the vector is sorted

        while (m--) {
            ll a, b, c;
            cin >> a >> b >> c;

            // Calculate the threshold for binary search
            ll threshold = b - 2 * sqrtl(a * c);

            // Perform binary search to find the smallest element greater than threshold
            ll result = binary_search(slopes, threshold);

            if (result != -1 && result < b + 2 * sqrt(a * c)) {
                cout << "YES\n" << result << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
