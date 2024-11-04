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
    ll t;
    cin >> t;

    while(t --){
        ll n;
        cin >> n;

        string ans = "";
        if(n % 2 == 0){
            ans += string(n - 2, '3');
            ans += "66";
        }
        else{
            if(n <= 3)
                ans = "-1";
            else{
                ans += string(n - 5,'3');
                ans += "36366";
            }
        }
        cout << ans << endl;
    }
}