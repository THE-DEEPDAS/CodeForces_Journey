// if we are standing at x, y then we can move only like (x + 1, y + 1) and (x - 1, y)
// minimum steps to move from (a , b) to (c , d)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll dist_in_y = d - b, dist_in_x = c - a;
        if(dist_in_y < 0){
            cout << -1 << endl;
        }
        else{
            // now you compulsary have to come ahead by dist_in_y steps 
            // so total number of times (x - 1, y) will occur will be
            dist_in_x = c - (dist_in_y + a);
            if(dist_in_x > 0){
                cout << -1 << endl;
            }
            else{
                cout << dist_in_y + abs(dist_in_x) << endl;
            }
        }
    }
}