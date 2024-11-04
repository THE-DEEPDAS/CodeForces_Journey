// n students have favourite drink in range 1 to k and each's favourite drink is denoted by ai
// there are infinite sets and each sets has 2 potions of drinks
// so minimum number of sets to give all 1 drink = ceil(n / 2) 
// find maximum number of students who will have favourite drinks
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> favourite_count(k, 0);
    ll favourite;
    for (ll i = 0; i < n; i++) {
        cin >> favourite;
        favourite_count[favourite - 1]++;
    }

    ll number_of_sets = (n + 1) / 2;
    sort(favourite_count.rbegin(), favourite_count.rend());

    ll ans = 0;
    ll sets_used = 0;
    vector<ll> odd_counts;

    for (ll count : favourite_count) {
        if (count % 2 == 0) {
            ans += count;
            sets_used += count / 2;
        } 
        else {
            odd_counts.push_back(count);
        }
    }

    ll remaining_sets = number_of_sets - sets_used;
    sort(odd_counts.rbegin(), odd_counts.rend()); 

    for (ll count : odd_counts) {
        if (remaining_sets == 0) break;
        ll pairs = min((count + 1) / 2, remaining_sets);
        ans += pairs * 2 - 1; 
        remaining_sets -= pairs;
    }

    cout << ans << endl;
}
