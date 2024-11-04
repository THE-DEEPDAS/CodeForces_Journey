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
    ll testcases;
    cin >> testcases;
    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        ll ans = 0;
        ll layers = min(n, m) / 2;
        
        for(ll layer = 0; layer < layers; layer++) {
            string curr;
            
            for(ll j = layer; j < m-layer; j++) 
                curr += grid[layer][j];
            
            for(ll i = layer+1; i < n-layer; i++) 
                curr += grid[i][m-1-layer];
          
            for(ll j = m-2-layer; j >= layer; j--) 
                curr += grid[n-1-layer][j];
            
            for(ll i = n-2-layer; i > layer; i--) 
                curr += grid[i][layer];
            
           
            curr += curr; 
            for(ll i = 0; i < curr.length()/2; i++) {
                if(curr[i] == '1' && curr[i+1] == '5' && 
                   curr[i+2] == '4' && curr[i+3] == '3') {
                    ans++;
                }
            }
        }
        
        cout << ans << "\n";
    }
}