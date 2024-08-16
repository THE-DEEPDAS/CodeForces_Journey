// distance between two points i and j is |i - j|
// i is closest to j if distance of any other point is greater than |i - j|
// add one point in this "set" to make it closest to everyone
// also points are in sorted order

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testcases;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++) {
        ll n;
        cin >> n;

        vector<ll> points(n);
        for (ll i = 0; i < n; ++i) {
            cin >> points[i];
        }

        if(n != 2){
            cout << "NO" << endl;
        }
        else{
            if(points[1] - points[0] > 1){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }

    }
}