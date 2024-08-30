// appleman has n cards and each has a capital letter written on it
// now postman gets coins = number of same cards he chooses for each same card
// means if he chooses 3 C's and 4 D's and 1 P then he will get 3*3 + 4*4 + 1
// find max amount of money he can get by picking k cards from the total n
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> freq(26 , 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    sort(freq.rbegin(), freq.rend());

    ll money = 0;
    for (ll i = 0; i < 26 && k > 0; i++) {
        if (freq[i] == 0) continue;
        ll take = min(k, freq[i]);
        money += take * take;
        k -= take;
    }

    cout << money << endl;
}