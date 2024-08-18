// a lucky number is a number made only with 7's and 8's
// we have number of digits , tell how many numbers of digits <= number of digits can be lucky
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    // total count of lucky numbers with up to n digits
    // formula for 2^1 + 2^2 + ... + 2^n = 2^(n + 1) - 2
    ll ans = (1LL << (n + 1)) - 2;

    cout << ans << endl;
}