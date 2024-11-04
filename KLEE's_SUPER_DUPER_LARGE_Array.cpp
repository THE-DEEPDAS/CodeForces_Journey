// klee has an array [k , k + 1, ... , k + n - 1]
// choose an index i such that |a1 + a2 + ... + ai - ai+1 - ... - an| is minimised
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n, k;
        cin >> n >> k;

        ll left = 1, right = n;
        while (right > left + 1) {
            ll i = left + (right - left) / 2;
            ll S1 = (k * i) + (i * (i - 1) / 2);
            ll S2 = ((k + i) * (n - i)) + ((n - i) * (n - i - 1) / 2);

            if (S1 < S2){
                left = i;
            } 
            else{
                right = i;
            }
        }

        ll ans = LLONG_MAX;
        // so now left and right are as close as possible so converged max
        for (ll i = left; i <= right; i++) {
            ll S1 = (k * i) + (i * (i - 1) / 2);
            ll S2 = ((k + i) * (n - i)) + ((n - i) * (n - i - 1) / 2);
            ans = min(ans, abs(S1 - S2));
        }
        cout << ans << endl;
    }
}