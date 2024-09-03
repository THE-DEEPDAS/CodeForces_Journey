// we have 2 integers a , b where a <= b and c such that a <= c <= b
// find minimum value of (c - a) + (b - c)
// so just print b - a
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b;
        cin >> a >> b;

        cout << b - a << endl;
    }
}