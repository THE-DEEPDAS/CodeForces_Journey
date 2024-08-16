// digital root is a single digit value that is sum of all numbers until it comes down to single digit
// n tasks : find kth positive number whose digital root is x
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll> answers(n);
    for(ll i = 0; i < n; i++){
        ll k, x;
        cin >> k >> x;

        // if x is 0, then kth positive number whose digital root is 0 is 0 itself
        if(x == 0){
            answers[i] = 0;
            continue;
        }
        else{

            for(ll i = 0; i < k; i++){
                
            }
        }
    }
}