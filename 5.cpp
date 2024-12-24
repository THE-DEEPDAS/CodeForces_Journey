#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int special = -1;
    ll special_val = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != 1 && a[i] != -1) {
            special = i;
            special_val = a[i];
            a[i] = 0;
        }
    }
    
    set<ll> sums = {0};
    ll curr = 0;
    vector<ll> prefix = {0};
    
    for(ll x : a) {
        curr += x;
        prefix.push_back(curr);
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            ll sum = prefix[j] - prefix[i];
            if(special != -1 && i <= special && special < j) {
                sum += special_val;
            }
            sums.insert(sum);
        }
    }
    
    cout << sums.size() << '\n';
    for(ll x : sums) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}