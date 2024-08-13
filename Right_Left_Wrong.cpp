// n cells with each cell having +ve integer ai and letter si = 'L' or 'R
// find max points by performing any number of operations
// in one operation we choose left and right where left = 'L' and right = 'R'
// add al to ar to current score
// replace si with '.' so can't use it again
// find max score that can be achieved
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n = 0;
        cin >> n;

        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<char> s(n);
        for(ll i = 0; i < n; i++){
            cin >> s[i];
        }
        
        vector<ll> prefix_sum(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
        }

        ll max_score = 0;

        for (ll i = 0; i < n; i++) {
            ll current_max_score = 0;
            if (s[i] == 'L') {
                for (ll j = i + 1; j < n; j++) {
                    if (s[j] == 'R') {
                        ll current_score = prefix_sum[j + 1] - prefix_sum[i];
                        max_score = max(max_score, current_score);
                    }
                }
            }
        }

        cout << max_score << endl;
    }
}