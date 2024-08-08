// we have (even number) n
// create an array of length n where first n/2 elements are even
// next n/2 elements are odd
// all are distinct and positive
// sum of 1st half = sum of 2nd half
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        if(n % 4 != 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            ll odds = 1, sum_odd = 0;
            ll evens = 2, sum_even = 0;
            vector<ll> a(n);
            
            for(ll i = 0; i < n / 2; i++){
                a[i] = evens;
                sum_even += a[i];
                evens += 2;
            }

            for(ll i = n / 2 + 1; i < n; i++){
                a[i] = odds;
                sum_odd += a[i];
                odds += 2;
            }

            a[n / 2] += sum_even - sum_odd;
            for(ll num : a){
                cout << num << " ";
            }
            cout << endl;
        }
    }
}