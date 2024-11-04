// we have all integers from l to r
// we can pick 2 numbers x and y , in place we can write 3x and floor(y / 3)
// min steps to make all 0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll l, r;
        cin >> l >> r;

        vector<ll> nums(r - l + 1);
        for (ll i = l; i <= r; i++){
            nums[i] = i;
        }

        ll i = l;
        while(true){
        }
    }
}