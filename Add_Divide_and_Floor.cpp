#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
 vector<ll> seq; // To store operations

        while (a[0] != a[n - 1]){
            if ((a[0] & 1) && (a[n - 1] % 2 == 0)){
                seq.push_back(1); // When first element is odd and last is even
                a[0] = (a[0] + 1) / 2;
                a[n - 1] = (a[n - 1] + 1) / 2;
            } 
            else{
                seq.push_back(0); 
                a[0] = (a[0]) / 2;
                a[n - 1] = (a[n - 1]) / 2;
            }
        }

        cout << seq.size() << endl;

        if (seq.size() <= n) {
            for (ll i = 0; i < seq.size(); i++) {
                cout << seq[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
