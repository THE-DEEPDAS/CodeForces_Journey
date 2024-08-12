#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll check_evens(ll r , ll g , ll b , ll w){
    
        ll evens = 0;

        if(r % 2 == 0){
            evens ++ ;
        }
        if(g % 2 == 0){
            evens ++ ;
        }
        if(b % 2 == 0){
            evens ++ ;
        }
        if(w % 2 == 0){
            evens ++ ;
        }
    return evens;
}

int main(){
    ll testcases = 0;
    cin >> testcases;
     bool found = false;

    while(testcases --){
        ll r , g , b , w;
        cin >> r >> g >> b >> w;
        
        ll evens = check_evens(r , g, b, w);
        if(evens >= 3){
            cout << "YES" << endl;
            continue;
        }

        if(r != 0){
            r--;
        }
        else{
            cout << "NO" << endl;
            continue;
        }

        if(g != 0){
            g--;
        }
        else{
            cout << "NO" << endl;
            continue;
        }

        if(b != 0){
            b--;
        }
        else{
            cout << "NO" << endl;
            continue;
        }

        w++;
        evens = check_evens(r , g , b , w);
        if(evens >= 3){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
        }
    }
}