// there are n cells where people live in a row
// one can travel from cell i to cell (i + ai) using the i-th portal.
// i am at cell 1 and want to go to cell t , is it possible?
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n , t;
    cin >> n >> t;

    vector<ll> a(n);
    for(ll i = 0; i < n - 1; i++){
        cin >> a[i];
    }

    ll i = 0;
    while(i < t - 1){
        i += a[i];
    }
    if(i == t - 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}