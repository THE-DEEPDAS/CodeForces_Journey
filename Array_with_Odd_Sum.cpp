// we have an array of n integers
// now we can have 2 indexes i and j and replace ai with aj
// find if we can get the sum of elements of the array = odd
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        bool odd = false;
        bool even = false;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            if(!odd && a[i] % 2 != 0) 
                odd = true;
            else if(!even && a[i] % 2 == 0)
                even = true;
        }
        
        if(sum % 2 != 0 || (odd && even)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}