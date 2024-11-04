// there are n cards with numbers on it
// we have to take maximum cards
// if in current turn we have taken cards of number x with it then next we can take card only with number x + 1
// we can take only k distinct number's card

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n, k;
        cin >> n >> k;
        
        vector<ll> cards(n);
        for (ll i = 0; i < n; i++) {
            cin >> cards[i];
        }

        sort(cards.begin(), cards.end());

        ll max_cards = 0;
        ll distinct_count = 0;
        ll left = 0;
        
        // Sliding window to count distinct numbers
        for (ll right = 0; right < n; right++) {
            if (right == 0 || cards[right] != cards[right - 1]) {
                distinct_count++;
            }

            while (distinct_count > k) {
                if (cards[left] != cards[left + 1]) {
                    distinct_count--;
                }
                left++;
            }
            
            max_cards = max(max_cards, right - left + 1);
        }

        cout << max_cards << endl;
    }

    return 0;
}
