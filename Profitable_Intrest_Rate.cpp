// we have a coins for depositing in an account
// b is the charge of opening the account
// if we deposit x coins in "opposite account" then price of b reduces to (b - 2*x)
// find the max money that can be deposited
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b;
        cin >> a >> b;

        if(a >= b)
            cout << a << endl;
        else{
            cout << max(0LL, a - (abs(b - a))) << endl;
        }
    }
}