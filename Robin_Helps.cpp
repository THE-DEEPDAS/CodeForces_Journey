#include<bits/stdc++.h>
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

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        ll gold = 0, cnt = 0;
        
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            
            if (a[i] >= k) {
                gold += a[i]; // Robin takes all gold if it meets the threshold
            }
            else if (a[i] == 0) {
                if (gold > 0) { // Robin gives gold if he has any
                    cnt++;
                    gold--; // He gives 1 gold
                }
            }
        }

        cout << cnt << endl;
    }
}
