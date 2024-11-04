// we need to find if the given string can be format of the emailid
// email id is of the type A@B
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr);                 // Untie cin and cout for faster input/output
    }
} fast_io_setup;

int main() {
    string s;
    cin >> s;

    vector<ll> positions;
    ll n = s.size();

    for (ll i = 0; i < n; i++) {
        if (s[i] == '@') {
            positions.push_back(i);
        }
    }

    ll si = positions.size();
    if (si == 0 || positions[0] == 0 || positions[si - 1] == n - 1) {
        cout << "No solution" << endl;
        return 0;
    }

    string ans = "";
    bool printed = false;
    bool start = true, last = false;
    string email = "";
    for (ll i = 0; i < n; i++) {
        if (i < si - 1 && positions[i + 1] - positions[i] <= 2) {
            cout << "No solution" << endl;
            printed = true;
            break;
        }
        if(start && s[i] != '@'){
            email += s[i];
        }
        else if(start && s[i] == '@'){
            email += s[i];
            start = false;
        }
        else if(!start && i - 1 != positions[si - 1] && !last){
            email += s[i];
            ans += email + ",";
            email = "";
            start = true;
        }
        else if(i - 1 == positions[si - 1]){
            last = true;
            email += s[i];
        }
        else if(last){
            email += s[i];
        }
    }
    ans += email;

    if (!printed) {
        cout << ans << endl;
    }
}
