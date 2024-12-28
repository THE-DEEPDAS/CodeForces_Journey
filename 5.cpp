#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

// Fast I/O setup
inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> precompute_factorials() {
    vector<ll> fact(101);
    fact[0] = 1;
    for(ll i = 1; i <= 100; i++) {
        fact[i] = i * fact[i-1];
    }
    return fact;
}

ll count_divisors(ll n) {
    if(n == 1) return 1;
    
    ll result = 1;
    ll count = 0;
    while(n % 2 == 0) {
        count++;
        n = n >> 1;  
    }
    if(count > 0) {
        result *= (count + 1);
    }
    
    for(ll i = 3; i * i <= n; i += 2) {
        count = 0;
        while(n % i == 0) {
            count++;
            n /= i;
        }
        if(count > 0) {
            result *= (count + 1);
        }
    }
    
    if(n > 1) {
        result *= 2;  
    }
    
    return result;
}

int main() {
    fast_io();
    vector<ll> factorials = precompute_factorials();
    ll N, M;
    cin >> N >> M;
    
    for(ll i = 0; i < N; i++) {
        ll Ai;
        cin >> Ai;
        ll result = count_divisors(Ai * factorials[M]) % MOD;
        cout << result;
        if(i < N-1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}