// new max or min in array then amazing
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll temp;
    cin >> temp;
    ll all_max = temp;
    ll all_min = temp;
    ll amazing = 0;
    for(ll i = 1; i < n; i++) {
        cin >> temp;
        if(temp > all_max) {
            all_max = temp;
            amazing++;
        }
        if(temp < all_min) {
            all_min = temp;
            amazing++;
        }
    }
    cout << amazing << endl;
}