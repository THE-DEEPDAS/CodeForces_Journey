// we can increase any element by a or b
// we want to make largest elemnt - smallest element = minimum possible
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n , a , b ;
        cin >> n, a, b;

        vector<ll> c(n);
        ll gcd = __gcd(a, b);
        for (ll i = 0; i < n; i++){
            cin >> c[i];
            c[i] = c[i] % gcd;
        }

        // maximum will always be b
        if(a > b){
            swap(a, b);
        }
        
    }
}