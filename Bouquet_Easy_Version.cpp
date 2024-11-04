// there are n flowers and a flower with k petals costs k coins
// we can't buy any 2 flowers who have difference of more than 1 in number of flower petals
// we have m coins , find max number of petals 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        sort(a.rbegin(), a.rend()); // Sort petals in ascending order
        ll total_cost = 0, petals_bought = 0;

        for (ll i = 0; i < n; i++) {
            // If this is not the first flower and the difference between consecutive petals > 1, break
            if(i > 0 && a[i] - a[i - 1] > 1) {
                break;
            }
            // Check if we can afford the current flower
            if(total_cost + a[i] <= m) {
                total_cost += a[i];  // Buy the flower
                petals_bought += a[i];  // Add its petals to the total
            } else {
                break;  // Stop if we can't afford this flower
            }
        }

        cout << petals_bought << endl;  // Output the maximum number of petals we can buy
    }
}
