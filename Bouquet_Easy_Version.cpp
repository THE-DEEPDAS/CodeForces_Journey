// there are n flowers and a flower with k petals costs k coins
// we can't buy any 2 flowers who have difference of more than 1 in number of flower petals
// we have m coins , find max number of petals 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        ll ans = 0, i = 0;
        while(ans + a[i] <= m){
            if(i < n - 1 && a[i + 1] - a[i] > 1){
                break;
            }
            ans += a[i++];
        }

        cout << ans << endl;
    }
}