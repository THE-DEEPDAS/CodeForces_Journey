// we need to pick coins from the available n coins such that we can have more valued coins then our twin
// here a[i] will have value of each coin
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend()); 
    ll my_sum = 0, twin_sum = 0;
    ll total_sum = accumulate(a.begin(), a.end(), 0LL); 
    twin_sum = total_sum; 

    ll coins_taken = 0;
    for (ll i = 0; i < n; i++) {
        my_sum += a[i];
        twin_sum -= a[i];
        coins_taken++;

        if (my_sum > twin_sum) {
            break;
        }
    }

    cout << coins_taken << endl; 
}
