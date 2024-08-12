#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll a , b , s;
    cin >> a >> b >> s;

    ll min_steps = abs(a) + abs(b);
    if(s >= min_steps && (s - min_steps) % 2 == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}