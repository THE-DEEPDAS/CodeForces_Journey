// for baking cookies we need n items , each item should be used ai grams
// we have bi amount of each items and k grams of magic powder which can be made into any ingredient
// find the maximum number of cookies we can make
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

ll possible(ll cookies, ll k, vector<ll> a, ll n, vector<ll>b){
    // so we want to check if we can make this many cookies
    // so we chaeck if we have enough powder to achieve this
    ll powder_needed = 0;  // total magic powder needed

    for (ll i = 0; i < n; i++) {
        // total amount of the i-th ingredient needed to make 'cookies' cookies
        ll total_needed = a[i] * cookies;

        // calc how much more of the ingredient is needed
        if (total_needed > b[i]) {
            powder_needed += total_needed - b[i];
        }

        // if the powder needed exceeds available magic powder, return false
        if (powder_needed > k) return false;
    }

    return true;  // if all checks pass, return true
}

int main(){
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++){
        cin >> b[i];
    }

    ll low = 0, high = 1e9, result = 0;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(possible(mid, k, a, n, b)){
            result = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << result << endl;
} 