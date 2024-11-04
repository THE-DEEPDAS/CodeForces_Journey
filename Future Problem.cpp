// find the number of digits in all numbers from 1 to n
// add the number of digits and display it as answer
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void countDigits(ll n) {
    // so 1 to 9 has 1 digit
    // 10 to 99 = 90 has 2 digits
    // 100 to 999 = 900 has 3 digits
    // 1000 to 9999 = 9000 has 4 digits
    // so on
    // so we need to find the number of digits in n
    // and then add the number of digits in all numbers from 1 to n
    // to find the number of digits in n, we can use the formula
    // number of digits = floor(log10(n)) + 1
    // but we need to add the number of digits in all numbers from 1 to n
    ll number_of_digits_in_n = floor(log10(n)) + 1;
    ll result = 0, multiplier = 1;
    for (ll i = 1; i < number_of_digits_in_n; i++){
        result += 9 * multiplier * i;
        multiplier *= 10;
    }
    // now add the number of numbers of before n with same number of digits as n
    // if multiplier is on x digits then largest number with n - 1 digits will be 9 repeated x times
    ll x = number_of_digits_in_n - 1;
    // now make a number with 9 repeated x times
    ll number = 0;
    for (int i = 0; i < x; i++) {
        number = number * 10 + 9;
    }
    // 123 - 99 = 24 so 24 numbers are there with 3 digits which we want to add in result
    result += number_of_digits_in_n * (n - number);

    cout << result << endl;
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;
        countDigits(n);
    }
}
