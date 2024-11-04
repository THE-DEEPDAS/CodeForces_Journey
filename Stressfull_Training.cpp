// n students, initial charging in laptop = ai
// he uses bi per minute and contest lasts for k minutes
// we buy 1 charger and want that all stidents should be able to use that charger
// so if it was consuming bi then after charging on that moinutye it used bi - x charge
// find x , the charge in last minute of contest doesn't matter
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool possible_to_charge(ll x, ll k, ll n, vector<ll>& initial_charge, vector<ll>& power_usage) {
    ll total_minutes_needed = 0;

    for (ll i = 0; i < n; i++) {
        ll total_usage = power_usage[i] * k;

        if (initial_charge[i] >= total_usage) continue;

        ll required_charge = total_usage - initial_charge[i];
        ll minutes_needed = required_charge % x == 0? required_charge / x : (required_charge / x) + 1;
        total_minutes_needed += minutes_needed;

        // if total minutes needed exceeds k at any point then not possible
        if (total_minutes_needed > k) return false;
    }
    return true;
}

int main(){
    ll n, k;
    cin >> n >> k;

    vector<ll> initial_charge(n);
    for(ll i = 0; i < n; i++) cin >> initial_charge[i];

    vector<ll> power_usage(n);
    for(ll i = 0; i < n; i++) cin >> power_usage[i];

    // use a binary search to check for the value of x
    ll left = 1, right = 1e12;
    ll ans = -1;
    while(left <= right){
        ll mid = left + (right - left) / 2;
        if(possible_to_charge(mid, k, n, initial_charge, power_usage)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
}