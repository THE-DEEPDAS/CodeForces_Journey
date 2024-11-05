// we have an array of numbers 'a' and we want to make an array of GCD(current element, next element) 'b'.
// we want to finc if it is possible to make b non-decreasing by removing exactly 1 element from a
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

bool isNonDecreasingGCDSequence(const vector<ll>& gcdSequence) {
    ll currentGCD = __gcd(gcdSequence[0], gcdSequence[1]);
    for (size_t i = 1; i < gcdSequence.size() - 1; i++) {
        ll nextGCD = __gcd(gcdSequence[i], gcdSequence[i + 1]);
        if (currentGCD > nextGCD) return false;
        currentGCD = nextGCD;
    }
    return true;
}

bool canMakeNonDecreasingGCDSequence() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll& num : arr) cin >> num;

    ll prevGCD = __gcd(arr[0], arr[1]);
    ll removeIndex = -1;

    for (ll i = 1; i < n - 1; i++) {
        ll currentGCD = __gcd(arr[i], arr[i + 1]);
        if (currentGCD < prevGCD) {
            removeIndex = i;
            break;
        }
        prevGCD = currentGCD;
    }

    if (removeIndex == -1) return true;

    vector<ll> test1 = arr, test2 = arr, test3 = arr;
    if (removeIndex > 0) test1.erase(test1.begin() + removeIndex - 1);
    test2.erase(test2.begin() + removeIndex);
    if (removeIndex < n - 1) test3.erase(test3.begin() + removeIndex + 1);

    return isNonDecreasingGCDSequence(test1) || isNonDecreasingGCDSequence(test2) || isNonDecreasingGCDSequence(test3);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        cout << (canMakeNonDecreasingGCDSequence() ? "YES" : "NO") << "\n";
    }
}