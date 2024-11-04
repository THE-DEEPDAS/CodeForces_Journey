// we have n points in 2D coordinates
// for points (xi , yi) it is given that 0 <= yi <= 1
// how many non-degenerate triangles can be made from 3 distinct points
// so main observation is y can only be 0 or 1 and for non-zero area we need 1 element from both the sets
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n;
        cin >> n;
        vector<ll> point_x_at_y0; // points with y = 0
        vector<ll> point_x_at_y1; // points with y = 1
        map<ll, ll> freq_x_at_y0; // frequency of x-coordinates with y = 0
        map<ll, ll> freq_x_at_y1; // frequency of x-coordinates with y = 1

        for (ll i = 0; i < n; i++){
            ll x, y;
            cin >> x >> y;
            if (y == 0) {
                point_x_at_y0.push_back(x);
                freq_x_at_y0[x]++;
            }
            else {
                point_x_at_y1.push_back(x);
                freq_x_at_y1[x]++;
            }
        }

        ll count = 0;

        // Case 1: choose 2 points from y = 0 and 1 point from y = 1
        for (ll x1 : point_x_at_y0) {
            for (ll x2 : point_x_at_y0) {
                if (x1 != x2) { 
                    if (freq_x_at_y1[x1] > 0 || freq_x_at_y1[x2] > 0) { // check if a matching point exists in y = 1
                        count++;
                    }
                }
            }
        }

        // Case 2: choose 2 points from y = 1 and 1 point from y = 0
        for (ll x1 : point_x_at_y1) {
            for (ll x2 : point_x_at_y1) {
                if (x1 != x2) {
                    if (freq_x_at_y0[x1] > 0 || freq_x_at_y0[x2] > 0) { // check if a matching point exists in y = 0
                        count++;
                    }
                }
            }
        }

        // each valid combination is counted twice
        cout << count / 2  + (count == 0 ? 0 : 1) << endl;
    }
}