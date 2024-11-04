// n rows and m columns , w gorillas agreed for photoshoot
// ith gorilla has height ai
// spectacle of k*k subsquare is sum of heights of gorillas
// maximum specatle arrangement
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n , m , k;
        cin >> n >> m >> k;

        ll w;
        cin >> w;

        vector<ll> heights(w);
        for(ll i = 0; i < w; i++){
            cin >> heights[i];
        }

        
    }
}