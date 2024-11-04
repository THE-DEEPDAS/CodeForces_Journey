// there are n cities in a line from 1 to n
// each city has 2 coloured portals
// there are total 4 colours
// to travel from city i to j costs |i - j| and possible only if same colour is there in i and jth city
// find minimum cost from city x to city y
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr); // Untie cin and cout for faster input/output
    }
} fast_io_setup; // This will be executed before main()

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, q;
        cin >> n >> q;

        vector<string> city(n);
        for (ll i = 0; i < n; i++)
            cin >> city[i];
        
        while(q--){
            ll x, y;
            cin >> x >> y;

            x--;
            y--;

            // i think this might be using tree or graph and i am still not completely aware of this topic so was not able to solve this
            
        }
    }
}