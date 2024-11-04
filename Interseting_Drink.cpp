// we have n shops selling a drink
// for q days we want to buy the drink 
// find the max number of shops from which we can buy the drink if we have different coins on each day
// coins required to buy the drink from n shops are given
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    vector<ll> price(n);
    for (ll i = 0; i < n; i++)
        cin >> price[i];

    ll q;
    cin >> q;

    sort(price.begin(), price.end());
    vector<ll> available_coins(q);
    for (ll i = 0; i < q; i++){
        cin >> available_coins[i];

        ll cnt = 0;
        ll left = 0, right = n - 1;
        while(left <= right){
            ll mid = left + (right - left) / 2;
            if(price[mid] <= available_coins[i]){
                cnt = mid + 1;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        cout << cnt << endl;
    }
}