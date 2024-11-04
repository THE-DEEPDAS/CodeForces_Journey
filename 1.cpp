#include <iostream>
using namespace std;
typedef long long ll;

// Function to calculate XOR from 0 to x
ll xor_upto(ll x) {
    if (x < 0) return 0; // Handle negative values gracefully
    switch (x % 4) {
        case 0: return x;
        case 1: return 1;
        case 2: return x + 1;
        case 3: return 0;
    }
    return 0; // This line should never be reached
}

// Function to calculate XOR from l to r
ll xor_range(ll l, ll r) {
    return xor_upto(r) ^ xor_upto(l - 1);
}

// Function to calculate interesting XOR
ll interesting_xor(ll l, ll r, ll i, ll k) {
    ll mod_val = 1LL << i; // Calculate 2^i
    ll full_xor = xor_range(l, r); // Full range XOR

    // Find first excluded number >= l
    ll start = (l + mod_val - (l % mod_val + k) % mod_val + k);
    
    if (start > r) return full_xor; // No excluded numbers in range

    // Count how many excluded integers are there
    ll count_excluded = (r - start) / mod_val + 1;

    // Calculate XOR of all excluded numbers using arithmetic series properties
    ll excluded_xor = 0;
    for (ll x = start; x <= r; x += mod_val) {
        excluded_xor ^= x;
    }

    // Return final result excluding those integers
    return full_xor ^ excluded_xor;
}

int main() {
    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll l, r, i, k;
        cin >> l >> r >> i >> k;
        cout << interesting_xor(l, r, i, k) << "\n";
    }

    return 0;
}