// we have a coins in Alice's wallet and b coins in Bob's wallet
// at a particular move we can ecvhange the wallet or keep ours and then remove 1 coin
// if no move possible he/she loses
// print the winner
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b;
        cin >> a >> b;

        if((a + b) & 1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
}