// there are m containers,ith container has ai matchboxes and each contains bi matches
// we can have maximum n matchboxes in the bag
// find maximum number of matches he can carry
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> matches(m);
    ll t1, t2;
    for (ll i = 0; i < m; i++){
        cin >> t1 >> t2;
        matches[i] = make_pair(t1, t2);
    }

    // Sort by the second value of the pair
    sort(matches.begin(), matches.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second > b.second;
    });

    ll ans = 0, matches_taken = 0;
    for (const auto& pair : matches){
        if(pair.first + ans < n){
            ans += (pair.first);
            matches_taken += (pair.first * pair.second);
        }
        else{
            matches_taken += ((n - ans) * pair.second);
            break;
        }
    }

    cout << matches_taken << endl;
}