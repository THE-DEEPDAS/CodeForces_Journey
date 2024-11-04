// we have to find out a , b , c three numbers 
// we have been given (a + b), (b + c), (a +c) and (a + b + c) in random order
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll a , b , c , d;
    cin >> a >> b >> c >> d;

    ll sum = max(max(a, b), max(c, d));
    if(sum == a){
        cout << a - b << " " << a - c << " " << a - d << endl;
    }
    else if(sum == b){
        cout << b - a << " " << b - c << " " << b - d << endl;
    }
    else if(sum == c){
        cout << c - a << " " << c - b << " " << c - d << endl;
    }
    else{
        cout << d - a << " " << d - b << " " << d - c << endl;
    }
}