// in a given array is it possible to make it in such a way that each number < its neighbours
// duplicates are allowed
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    // idea is that if the largest element is too large, it will dominate any possible arrangement,
    // making it impossible for the sum of its two neighbors to be greater than this largest element.
    if (a[n - 1] >= a[n - 2] + a[n - 3]) {
        cout << "NO" << endl;
    } 
    else {
        cout << "YES" << endl;
        cout << a[n - 1] << " ";
        for(ll i = n - 3; i >= 0; i--){
            cout << a[i] << " ";
        }
        cout << a[n - 2] << endl;
    }
    
}