// there are n rooms and in ith room we can install max of ci radiators
// each radiators have some sections so the one with k radiators cost k^2 burles
// we need at least sum(i) sections in ith room
// calculate min cost to set up not more than ci radiators with not less than sum(i) sections
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll> sum(n);
    vector<ll> c(n);
    for(ll i = 0; i < n; i++){
        cin >> c[i] >> sum[i];
    }

    for(ll i = 0; i < n; i++){
        if(sum[i] % c[i] == 0){
            cout << (sum[i] / c[i]) * (sum[i] / c[i]) * c[i] << endl;
        }
        else if(sum[i] < c[i]){
            // in this case we will buy all radiators with 1 section to reduce the cost
            // so sum[i] radiators of cost = 1^2 = 1
            cout << sum[i] << endl;
        }
        else{
            // sum[i] > c[i] but not divisible
            // x is the number of sections required per radiatore minimum
            // r are the remainging sections 
            // so c[i] - r will have x sections and r will have x + 1 sections
            ll x = sum[i] / c[i];
            ll r = sum[i] % c[i];
            ll cost = r * (x + 1) * (x + 1) + (c[i] - r) * x * x;
            cout << cost << endl;
        }
    }
}