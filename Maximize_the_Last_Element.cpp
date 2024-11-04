// arra of (n odd) integers
// 1 3 7 5 4 9 2 1 5
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll size_;
        cin >> size_;
      
       ll maximum = 0;
       vector<ll> a(size_); 
       for(ll j = 0; j < size_; j++){ 
         
           cin >> a[j];
           if(j % 2 == 0) maximum = max(maximum, a[j]);
        }
        cout << maximum << endl;
    }
}