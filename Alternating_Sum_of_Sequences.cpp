// so we need to find a1 - a2 + a3 - a4 + a5 - a6...
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        ll ans = 0;
        vector<ll> a(n);
        bool alternator = true;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            if (alternator){
                ans += a[i];
                alternator = false;
            }
            else{
                alternator = true;
                ans -= a[i];
            }
        }

        cout << ans << endl;
    }
}