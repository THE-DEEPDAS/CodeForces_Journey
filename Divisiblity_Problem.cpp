// we have 2 numbers a and b
// in one move we can make a = a + 1
// find minimum number of moves to make a divisible by b
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll a, b;
        cin >> a >> b;

        ll steps = 0;
        if(a == b || a % b == 0){
            cout << steps << endl;
            continue;
        }
        steps = b - (a % b);
        cout << steps << endl;
    }
}