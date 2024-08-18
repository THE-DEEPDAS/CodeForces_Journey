// 3 monsters have a , b and c health points
// every 7th shot is enhanced shot which deals damage to all the monsters
// we want to kill all at a particular point of time
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll a, b, c;
        cin >> a >> b >> c;
        ll sum = a + b + c;

        // so main thing is we check can we distribute shots by 1st condition and then check if someone runs out of
        // damage before them all togather
        if(sum % 9 == 0 && min({a, b, c}) >= sum / 9){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}