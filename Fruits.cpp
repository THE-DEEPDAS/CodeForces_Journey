// m fruits we want to buy
// the list of price of fruits(not particular for 'a' fruit means labels not assigned to fruits)
// find the min and max price of fruits possible
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

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> price_tags(n);
    for (ll i = 0; i < n; i++){
        cin >> price_tags[i];
    }
    sort(price_tags.begin(), price_tags.end());

    unordered_map<string, ll> fruits_map;
    for (ll i = 0; i < m; i++){
        string fruit_name;
        cin >> fruit_name;
        fruits_map[fruit_name]++;
    }

    vector<pair<string, ll>> fruits(fruits_map.begin(), fruits_map.end());

    // Sort the vector based on the second parameter (value) in decreasing order  
    sort(fruits.begin(), fruits.end(), [](const auto& a, const auto& b) {  
        return a.second > b.second; // Compare by the value in decreasing order  
    });  

    ll no_of_fruits = fruits.size();
    ll min_price = 0, max_price = 0;
    // so what we have as of now is that price is sorted in ascending order and fruits are sorted in 
    // descending order of frequencies
    // so for minimum price traverse in the price in from start
    for (int i = 0; i < no_of_fruits; i++){
        min_price += fruits[i].second * price_tags[i];
    }
    // and for maximum price traverse in the price form end
    for (int i = 0; i < no_of_fruits; i++){
        max_price += fruits[i].second * price_tags[n - 1 - i];
    }

    cout << min_price << " " << max_price << endl;
}