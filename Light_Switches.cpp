// so we have n appartments with each's light initially turned off
// to control lighting , chips are installed in the rooms
// a[i] is the time at which the chip were installed in the rooms
// after each k minutes , it changes the state of light
// find the minimum time when all are lit up
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool possible(ll mid, vector<ll>& a, ll k) {
      for (ll i = 0; i < a.size(); i++) {
        // Time since the chip was installed
        ll time_since_install = mid - a[i];
        // If time is negative or the number of cycles is even, light is off
        if (time_since_install < 0 || (time_since_install / k) % 2 == 1) {
            return false;
        }
    }
    return true;
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        // apply binary search
        ll left = 1, right = 1e12, ans = -1;
        while(left <= right){
            ll mid = left + (right - left) / 2;
            if(possible(mid , a , k)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        cout << ans << endl;
    }
}