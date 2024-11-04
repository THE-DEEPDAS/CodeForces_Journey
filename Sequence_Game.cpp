// we have an array of integers a 
// we will be given array of integers b such that it has first element + all ai such that a(i-1) <= ai
// we need to output any possible sequence a but len(a) can max be 2 * len(b)
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n = 0;
        cin >> n;

        vector<ll> b(n);
        for(ll i = 0; i < n; i++){
            cin >> b[i];
        }

        vector<ll> a;
        a.push_back(b[0]);

        for(ll i = 1; i < n; i++){
            if(b[i-1] > b[i]){
                a.push_back(1);  
            }
            a.push_back(b[i]);  
        }

        cout << a.size() << endl;
        for(ll i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}