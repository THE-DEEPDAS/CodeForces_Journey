// f(string) = number of distinct chars
// split in 2 strings a and b such that f(a) + f(b) = maximum
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        std::array<int, 26> cntl{}, cntr{};
        int res = 0;

        // so we first assume all are in right string only

        // Count distinct characters in the right part
        for (auto c : s) {
            res += !cntr[c - 'a']++;
        }

        int ans = res;
        // now we add the chars to the left substring

        // Iterate through the string to calculate maximum distinct characters
        for (auto c : s) {
            res += !cntl[c - 'a']++; // Add to left count
            res -= !--cntr[c - 'a']; // Remove from right count
            ans = max(ans, res); // Update maximum
        }

        cout << ans << endl; // Output the result
    }
}
