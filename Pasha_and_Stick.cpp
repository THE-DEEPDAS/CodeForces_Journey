// pasha has a stick of length n and we need to make 3 cuts
// how to cut it in the a way that we can make only rectangle and not square
// find the number of ways
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    
    // brute force solution shows TLE
    // ll count = 0;
    
    // for (ll a = 1; a <= n / 2; a++) {
    //     for (ll b = a; b <= (n - a) / 2; b++) {
    //         if ((2 * a + 2 * b) == n) {
    //             if (a != b) {
    //                 count++;
    //             }
    //         }
    //     }
    // }
    
    // cout << count << endl;

    ll count = 0;
    for(ll a = 1; a <= n / 2; a++){
        ll b = (n - (2 * a)) / 2;
         if(b > a && (2 * a + 2 * b) == n) {
            count++;
        }
    }

    cout << count << endl;
}
