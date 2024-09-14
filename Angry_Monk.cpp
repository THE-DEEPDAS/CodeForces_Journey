// n meters long potato caseroll, he cut it into k pieces , each of length a[i]
// we can make 2 pieces of length 1 , ai - 1 is ai >= 2
// pick a slice ai and aj = 1 and make ai + 1 by combining both
// find minimum number of operations to merge it into n(i.e. single piece)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(k);
        ll count_1 = 0;
        for (ll i = 0; i < k; i++){
            cin >> a[i];
            count_1++;
        }
        ll steps = count_1;
        n -= steps;
        
    }
}