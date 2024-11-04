// when we attack the dragon , the dragon is poisoned for next k seconds
// dragon has h hitpoints , find minimum possible value of k
// we can do exactly n attacks
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

bool possible(ll k, ll n, ll h, vector<ll>attack_time){
    // using binary search to check if we can kill the monstor in the current k value
    ll damage = 0;
    for (ll i = 0; i < n - 1; i++){
        damage += min(k, attack_time[i + 1] - attack_time[i]);
        if(damage >= h){
            return true;
        }
    }
    damage += k; // as last damage will always be of k points
    return damage >= h;
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, h;
        cin >> n >> h;

        vector<ll> attack_time(n);
        for (ll i = 0; i < n; i++){
            cin >> attack_time[i];
        }

        ll left = 1, right = 1e18, result = -1; // as h is in range 1e18
        while(left <= right){
            ll mid = left + (right - left) / 2;
            if(possible(mid , n , h , attack_time)){
                result = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        cout << result << endl;
    }
}