// we need to find k points of the form x, y such that each point is different 
// but average of all points = xc , yc
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll xc , yc , k;
        cin >> xc >> yc >> k;

        if(k % 2 != 0){
            cout << xc << " " << yc << endl;
            k--;
        }
        for (ll i = 1; i <= k / 2; i++){
            cout << xc - i << " " << yc << endl;
            cout << xc + i << " " << yc << endl;
        }
    }
}