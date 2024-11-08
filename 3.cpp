#include <bits/stdc++.h>
using namespace std;

struct Platform {
    int h, l, r, index;
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Platform> platforms(n);

        // Read platform data
        for (int i = 0; i < n; i++) {
            cin >> platforms[i].h >> platforms[i].l >> platforms[i].r;
            platforms[i].r = platforms[i].l + platforms[i].r; // right edge
            platforms[i].index = i; // Store the original index
        }

        // Sort platforms by height
        sort(platforms.begin(), platforms.end(), [](const Platform& p1, const Platform& p2) {
            return p1.h < p2.h;
        });

        // Result array to store minimum drop for each platform
        vector<int> result(n, INT_MAX);

        // For each platform, calculate the minimum possible maximum drop
        for (int i = 0; i < n; i++) {
            int minDrop = INT_MAX;

            // Find all platforms below the current one that the ball can fall onto
            for (int j = 0; j < i; j++) {
                if (platforms[j].h < platforms[i].h && (
                    (platforms[j].r >= platforms[i].l && platforms[j].l <= platforms[i].r) ||
                    (platforms[i].r >= platforms[j].l && platforms[i].l <= platforms[j].r))) {

                    // Calculate the vertical drop between platform i and platform j
                    int drop = abs(platforms[i].h - platforms[j].h);
                    minDrop = min(minDrop, drop);
                }
            }

            // If no valid platform is found below, the drop is just the height
            if (minDrop == INT_MAX) {
                result[platforms[i].index] = platforms[i].h;
            } else {
                result[platforms[i].index] = minDrop;
            }
        }

        // Output the result for the test case
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
