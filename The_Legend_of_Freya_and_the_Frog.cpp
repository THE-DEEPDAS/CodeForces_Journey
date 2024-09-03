// we are at origin and want to go to (x , y)
// in 1 step we choose an integer d , 0 <= d <= k
// on first move we are facing positive x direction
// we alternate facing like +x and +y in each time
// find the minimum number of steps to reach the destination
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b, k;
        cin >> a >> b >> k;

        ll dist_in_x = (a / k + (a % k == 0 ? 0 : 1));
        ll dist_in_y = (b / k + (b % k == 0 ? 0 : 1));
        if(dist_in_x > dist_in_y){
            cout << 2 * dist_in_x - 1 << endl;
        }
        else{
            cout << 2 * dist_in_y << endl;
        }
    }
}