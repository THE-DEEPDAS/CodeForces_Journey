// we have a cyclic array of n operations and we can do n - 1 operations on any element of the array
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;
        unordered_map<ll, ll> mpp;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            mpp[arr[i]] ++;
        }

        ll max_occurings = 0;
        for (auto& pair : mpp) {
            max_occurings = max(max_occurings, pair.second);
        }

        cout << n - max_occurings << endl;

    }
}