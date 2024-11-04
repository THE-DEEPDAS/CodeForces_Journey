// 3 +ve integers x, y, z are given
// find a,b,c such that x = max(a, b) and y = max(a, c) and z = max(b, c)
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll x, y, z;
        cin >> x >> y >> z;
        
        if(x == y){
            if(x >= z){
                cout << "YES" << endl;
                cout << x << " " << z << " " << z << endl;
            }
            else{
                cout << "NO"<< endl;
            }
        }
        else if(y == z){
            if(y >= x){
                cout << "YES" << endl;
                cout << y << " " << x << " " << x << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if(x == z){
            if(x >= y){
                cout << "YES" << endl;
                cout << x << " " << y << " " << y << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else cout << "NO" << endl;
    }
}