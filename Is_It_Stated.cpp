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
        string s;
        cin >> s;

        bool printed = false;
        ll n = s.size();
        for (ll i = 0; i < n - 1; i++){
            if(s[i] == 'i'){
                if(s[i + 1] == 't'){
                    cout << "YES" << endl;
                    printed = true;
                    break;
                }
            }
        }
        
        if(!printed)
            cout << "NO" << endl;
    }
}