// to make an array de - sorted we can do only 1 operation
// choose an index i and do a1 to ai ++ and ai+1 to an --
// minimum operations to make array non-sorted
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        // case 1 : same elements then 1 is the answer always
        // case 2 : already unsorted then answer is 0
        // case 3 : find the min difference between 2 elements then answer is diff / 2 + 1
        if(!is_sorted(a.begin(), a.end())){
            cout << 0 << endl;
        }
        else{
            ll min_diff = INT_MAX;
            for(ll i = 0; i < n - 1; i++) {
                min_diff = min(abs(a[i + 1] - a[i]) , min_diff);
            }
            if(min_diff > 0){
                cout << (min_diff) / 2 + 1 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
    }
}