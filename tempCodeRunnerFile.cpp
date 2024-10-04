#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t; // Read number of test cases

    while (t--) {
        ll b, c, d;
        cin >> b >> c >> d; // Read b, c, and d
        
        ll a = 0; // Initialize a
        bool valid = true; // Flag to check if a is valid

        for (int i = 0; i < 64; ++i) {
            ll bit_b = (b >> i) & 1; // Get the i-th bit of b
            ll bit_c = (c >> i) & 1; // Get the i-th bit of c
            ll bit_d = (d >> i) & 1; // Get the i-th bit of d
            
            if (bit_d == 1) {
                // If d's bit is 1
                if (bit_b == 0) {
                    a |= (1LL << i);
                } else if (bit_c == 1) {
                    valid = false;
                    break;
                }
            } else { // bit_d == 0
                // If c's bit is 0
                if (bit_b == 1) {
                    if (bit_c == 0) {
                        valid = false;
                        break;
                    }
                    a |= (1LL << i);
                }
            }
        }

        // Output the result
        if (valid && ((a | b) - (a & c) == d)) {
            cout << a << endl; // Output the valid a
        } else {
            cout << -1 << endl; // Output -1 if no valid a found
        }
    }

    return 0;
}
