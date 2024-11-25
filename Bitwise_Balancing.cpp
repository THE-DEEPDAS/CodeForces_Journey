#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll b, c, d;
        cin >> b >> c >> d;
        
        ll a = 0;
        bool valid = true;

        for (int i = 0; i < 64; ++i) {
            ll bit_b = (b >> i) & 1;
            ll bit_c = (c >> i) & 1;
            ll bit_d = (d >> i) & 1;
            
            if (bit_d == 1) {
                if (bit_c == 0) {
                    a |= (1LL << i);
                } 
                else if (bit_b == 0) {
                    valid = false;
                    break;
                }
            } 
            else {
                if (bit_c == 1) {
                    a |= (1LL << i);
                } 
                else if (bit_b == 1) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid && ((a | b) - (a & c) == d)) {
            cout << a << endl;
        } 
        else {
            cout << -1 << endl;
        }
    }
}
