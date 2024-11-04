// we are given the coordinates of forces and we need to find if it is equilibrium
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;  // number of forces

    ll sum_x = 0, sum_y = 0, sum_z = 0;
    for(ll i = 0; i < n; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }

    if(sum_x == 0 && sum_y == 0 && sum_z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}