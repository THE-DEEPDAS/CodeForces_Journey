// we have sequence of integers of length n with initial values = -1
// we have 2 typewriters , one writes from left to right and other in reverse (pointer = n)
// choose one typewriters and perform operations until it becomes permutation of [1 , 2, ... , n]
// write a number which is not in a to ai when current element = -1
// return the pointer to its intial position like 1 for 1st one and n for 2nd one (carriage return)
// move the pointer to next position like i = i + 1 for 1st one and i = i - 1 for 2nd one
// from both the typewriters same min number of carriage return should come
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;
        
        if(n % 2 == 0){
            cout << -1 << endl;
        }
        else{
            vector<ll> ans(n);
            ll odds = 3, evens = 2;
            ll idx = 0;
            while(odds <= n){
                ans[idx++] = odds;
                odds += 2;
            }
            idx = n / 2 + 1;
            while(evens <= n){
                ans[idx++] = evens;
                evens += 2;
            }
            ans[n / 2] = 1;

            for(ll i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}