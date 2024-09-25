// there is a cubical planet
// there are 2 flies on this planet
// they can see each other if they are on same side of the cube
// we have to find out if they are seing each other or not
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c;
    ll x, y , z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    ll counter = 0;
    if(a == x)
        counter++;
    if(b == y)
        counter++;
    if(c == z)
        counter++;
    
    if(counter >= 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}