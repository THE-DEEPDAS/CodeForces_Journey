// he has n instruments and each ith one take ai days to be learned
// he dedicates k days to learn max possible musical insturments
// we also have to print the index of musical instrument used

typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll n , k;
    cin >> n >> k;

    vector<ll> learn_in(n);
    for(ll i = 0; i < n; i++){
        cin >> learn_in[i];
    }

    // Create a vector of pairs where each pair is (days required, original index)
    vector<pair<ll, ll>> indices_map(n);
    for (ll i = 0; i < n; i++) {
        indices_map[i] = {learn_in[i], i};
    }

    // Sort by days required
    sort(indices_map.begin(), indices_map.end());

    ll instruments = 0, days = 0;
    vector<ll> learnt;

    for (const auto entry : indices_map) {
        if (days + entry.first <= k) {
            days += entry.first;
            learnt.push_back(entry.second + 1); // store the original index
            instruments++;
        } 
        else {
            break;
        }
    }

    // Output the results
    cout << instruments << endl;
    for (ll i : learnt) {
        cout << i << " ";
    }
}