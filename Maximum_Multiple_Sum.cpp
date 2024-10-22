// we have a number n
// we need to find a number x between 2 and n such that its multiples <= n's sum is max
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        if(n <= 3)
            cout << n << endl;
        else
            cout << 2 << endl;
    }
}