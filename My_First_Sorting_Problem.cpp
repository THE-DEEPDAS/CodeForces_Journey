// we have 2 numbers x and y
// output minimum of the 2 and maximum of the 2
// the user is giving the username as the input
// if it is not present in the database print OK 
// if it is present in the database then 1st time add name like username1 then username2 ...
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll x, y;
        cin >> x >> y;

        if(x > y)
            swap(x, y);

        cout << x << " " << y << endl;
    }
}