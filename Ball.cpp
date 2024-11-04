// if a women has lesser bequty, intelligence and richness then they will do suicide
// find the number of probable suicides
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Struct to represent a lady with beauty, intellect, and richness
struct Lady {
    ll beauty, intellect, richness;
};

// Comparator to sort ladies by beauty
bool compare(const Lady &a, const Lady &b) {
    return a.beauty > b.beauty;
}

int main() {
    ll n;
    cin >> n;

    vector<Lady> ladies(n);

    for (ll i = 0; i < n; i++){
        cin >> ladies[i].beauty;
    }
    
    for (ll i = 0; i < n; i++){
        cin >> ladies[i].intellect;
    }

    for (ll i = 0; i < n; i++){
        cin >> ladies[i].richness;
    }

    sort(ladies.begin(), ladies.end(), compare);

    ll result = 0;

    // To track the maximum intellect and richness values
    multiset<pair<ll, ll>> max_ir_set;  // Stores pairs of (intellect, richness)

    // Traverse through the sorted ladies
    for (ll i = 0; i < n; i++) {
        ll cur_intellect = ladies[i].intellect;
        ll cur_richness = ladies[i].richness;

        // If there's already a lady in the set with greater intellect and richness
        auto it = max_ir_set.lower_bound({cur_intellect + 1, cur_richness + 1});
        if (it != max_ir_set.end()) {
            result += 1; // This lady is a probable suicide case
        }

        // Insert the current lady's intellect and richness into the set
        max_ir_set.insert({cur_intellect, cur_richness});
    }

    cout << result << endl;
}
