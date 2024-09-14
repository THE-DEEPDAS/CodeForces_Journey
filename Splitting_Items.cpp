// we have n items and ith item has cost a[i]
// alice wants to take max cost items and bob the least ones
// they take turns starting from alice
// bob can increase the cost of several items by <= k if he wants to
// find the minimum possible score A - B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll A = 0, B = 0;
        bool switcher = true;
        for (ll i = n - 1; i >= 0; i--){
            if(switcher){
                A += a[i];
                switcher = false;
            }
            else{
                B += a[i] + k;
                switcher = true;
            }
        }
            if (A - B <= 0)
            {
                cout << 0 << endl;
            }
            else{
            cout << A - B << endl;
        }
    }
}