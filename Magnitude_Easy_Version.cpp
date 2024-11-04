// we take c = 0 initially and then we can do either c += a[i] or c = |c + a[i]|
// let k be the max number that can be formed from going from i = 0 to n -1
// print k
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        ll c = 0, temp = 0;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            temp += a[i];
            c += a[i];
            c = max(abs(temp), c);
            c = max(c , abs(c));
        }
            
        cout << c << endl;
    }
}