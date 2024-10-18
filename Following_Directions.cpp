// string for length n and we have to perform n moves
// starting from origin
// there is a candy at (1, 1) find if we can ever pass the candy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        ll x_coordinate = 0, y_coordinate = 0;
        bool printed = false;

        for(char c : s){
            if(c == 'R')
                x_coordinate++;
            else if(c == 'L')
                x_coordinate--;
            else if(c == 'U')
                y_coordinate++;
            else
                y_coordinate--;
            
            if(x_coordinate == 1 && y_coordinate == 1){
                cout << "YES" << endl;
                printed = true;
                break;
            }
        }

        if(!printed)
            cout << "NO" << endl;
    }
}