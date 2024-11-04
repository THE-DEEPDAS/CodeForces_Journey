#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        
        map<ll, vector<ll>> brand_costs;
        for(ll i = 0; i < k; i++) {
            ll b, c;
            cin >> b >> c;
            brand_costs[b].push_back(c);
        }
        
        vector<ll> brand_total;
        for(auto& p : brand_costs) {
            ll sum = 0;
            for(ll x : p.second) sum += x;
            brand_total.push_back(sum);
        }
        
        sort(brand_total.rbegin(), brand_total.rend());
        ll ans = 0;
        for(ll i = 0; i < min(n, (ll)brand_total.size()); i++) {
            ans += brand_total[i];
        }
        cout << ans << "\n";
    }
}