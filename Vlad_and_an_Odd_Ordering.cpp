// we have n cards, first put odd cards in ascending order
// then put down the card i.e. in multiple of 2 of these odd numbers
// then 3 * odd numbers then 4 * odd numbers
// so on
// find the kth card that we will put down
// also remeber for 3*odd, 5*odd no need to calculate as odd numbers put all those numbers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findKthCard(ll totalCards, ll k) {
    ll multiplier = 1;
    
    while (true) {
        ll oddCount = (totalCards + 1) / 2;
        
        if (k <= oddCount) {
            return (2 * k - 1) * multiplier;
        }
        
        k -= oddCount;
        totalCards -= oddCount;
        multiplier *= 2;
    }
}

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n, k;
        cin >> n >> k;
        
        // see what i am doing here is the difference between the numbers is like 2, 4, 6, 8
        // and i want to calculate how many numbers <= n are there in this range
        // so for example 6 is the current_diff and for 6 then first number will always be diff/2 i.e. 3
        // so n - 3 first and then the remaining numbers / current_diff will give total
        // but add 1 as 1st number was 3
        // then reduce the numbers in this range if k is > range numbers and find the diff in which k lies
        // then print the number using the first number + k - 1 * diff 
        
        cout << findKthCard(n, k) << endl;
    }
    return 0;
}
