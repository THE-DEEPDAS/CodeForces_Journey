// oldest brother = number 1, middle brother = number 2, smallest brother = number 3
// if we have 2 brothers who came on time in meet , find the one who came late
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;

    for (ll i = 0; i < 3; i++){
        if(a != (i + 1) && b != (i + 1)){
            cout << (i + 1);
            return 0;
        }
    }
}