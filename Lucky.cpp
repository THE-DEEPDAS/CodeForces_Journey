// ticket = string of 6 digits
// lucky = sum of first 3 digits = sum of last 3 digits
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testcases;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++) {
        string ticket;
        cin >> ticket;
        ll sum1 = 0, sum2 = 0;
        for(ll i = 0; i < 3; i++) {
            sum1 += ticket[i];
        }
        for(ll i = 3; i < 6; i++) {
            sum2 += ticket[i];
        }
        if(sum1 == sum2) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
}
