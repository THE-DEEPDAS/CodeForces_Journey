// k players, n cards and m jokers, start = each gets n / k cards
// the one with max joker wins and he gets point = x - y
// x = winner's joker count , y = 2nd placed player's joker count
// calculate max number of points a player can get
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n , m , k;
        cin >> n >> m >> k;

        ll winners_joker = min(n / k, m);
        ll seconds_joker = ((m - winners_joker) / (k - 1)) + ((m - winners_joker) % (k - 1) == 0 ? 0 : 1);
        cout << winners_joker - seconds_joker << endl;
    }
}