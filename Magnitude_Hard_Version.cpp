// we take c = 0 initially and then we can do either c += a[i] or c = |c + a[i]|
// let k be the max number that can be formed from going from i = 0 to n -1
// print the number of ways to reach k
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        ll positives = 0, negatives = 0;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            if (a[i] >= 0) positives++;
            else negatives++;
        }

        ll ans = 0;
        ans += static_cast<ll>(pow(2LL, positives)) % MOD;
        
    }
}