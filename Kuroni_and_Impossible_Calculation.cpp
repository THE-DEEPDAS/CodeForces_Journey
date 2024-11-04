// we need to find pie(aj - ai) which will be maximum
// pie means multiplication
// so we will multiply all
// take modulo with m and then print answer
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
        ll n, m;
        cin >> n >> m;

        vector<ll> numbers(n);
        for (ll i = 0; i < n; i++){
            cin >> numbers[i];
        }

        ll ans = 1;
        for (ll i = 0; i < n - 1; i++){
            ans *= (numbers[i] * numbers[i - 1]) % m;
        }

        cout << ans % m << endl;
    
}