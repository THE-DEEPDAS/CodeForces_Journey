// we have an permutation a of length n ans we want to make a permutation b such that
// a1 + b1 <= a2 + b2 <= a3 + b3 <= an + bn
// permutation always has all distinct elements
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }

        // vector<ll> copy = a;
        // 
        // reverse(a.begin(), a.end());
        // if(is_sorted(a.begin(), a.end())){
        //     for(ll i = 0; i < n; i++){
        //         cout << a[i] << " ";
        //     }
        //     cout << endl;
        // }
        // else{
        //     sort(a.begin(), a.end());
        //     for(ll i = 0; i < n - 1; i++){
        //         if(a[i] + copy[i] > a[i + 1] + copy[i + 1]){
        //             swap(a[i], a[i + 1]);
        //         }
        //     }
        //     for (ll i = 0; i < n; i++){
        //         cout << a[i] << " ";
        //     }
        //         cout << endl;
        // }
        // unordered_map<ll, ll> mpp;
        // for (ll i = 0; i < n; i++){
        //     mpp[i] = a[i];
        // }
        // sort(a.begin(), a.end());
        // vector<ll> ans(n);
        // vector<ll> sums = a;
        // for (ll i = 0; i < n; i++){
        //     ans[i] = i + 1;
        //     sums[i] += ans[i];
        // }
        // if(is_sorted(sums.begin(), sums.end())){
        //     cout << "YES" << endl;
            
        //     cout << endl;
        // }
        // else{
        //     cout << "NO" << endl;
        // }
        for (ll i = 0; i < n; i++){
            // we take equality condition for simplicity
            // so a1 + b1 = a2 + b2 ...
            cout << n + 1 - a[i] << " ";
        }
        cout << endl;
    }
}