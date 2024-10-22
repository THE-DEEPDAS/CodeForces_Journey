#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to compute edit distance between two strings
int editDistance(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    
    // Create a 2D DP array to store edit distances
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i; // Deleting all characters from str1
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j; // Inserting all characters to str1 to match str2
    }

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    // Deletion
                                    dp[i][j - 1],    // Insertion
                                    dp[i - 1][j - 1] // Substitution
                                   });
            }
        }
    }

    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--; // Convert to 0-based indexing

            // Extract substrings
            string sub_a = a.substr(l, r - l + 1);
            string sub_b = b.substr(l, r - l + 1);

            // Sort the substrings lexicographically
            sort(sub_a.begin(), sub_a.end());
            sort(sub_b.begin(), sub_b.end());

            // Calculate edit distance between the sorted substrings
            int result = editDistance(sub_a, sub_b);
            cout << result << "\n";
        }
    }

    return 0;
}
