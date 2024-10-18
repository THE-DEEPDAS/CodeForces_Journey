// 5 to 9 = large numbers
// positive number is large if all numbers are large
// given a number n, can it be sum of 2 large numbers
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll digits(ll num){
    return log10(num) + 1;
}

inline bool all_large(ll num) {
    while (num > 0) {
        if (num % 10 < 5)
            return false;
        num /= 10;
    }
    return true;
}

bool can_be_sum_of_two_large(ll n) {
    ll half_digits = digits(n) / 2; // Half the number of digits in n
    ll lower_limit = pow(10, half_digits - 1); // Minimum large number with half the digits
    ll upper_limit = pow(10, half_digits) - 1; // Maximum large number with half the digits

    // Check if there are two large numbers that sum to n
    for (ll i = lower_limit; i <= upper_limit; i++) {
        ll complement = n - i;
        if (all_large(i) && all_large(complement) && complement >= lower_limit && complement <= upper_limit) {
            return true;
        }
    }
    return false;
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        ll num_digits = digits(n);
        if(num_digits & 1LL){
            cout << "NO" << endl;
            continue;
        }

        if(all_large(n)){
            cout << "YES" << endl;
        }
        else if (can_be_sum_of_two_large(n)) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
