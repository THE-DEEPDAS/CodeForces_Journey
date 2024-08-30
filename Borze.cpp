// digit 0 is transmitted as <<.>>
// digit 1 is transmitted as <<-.>>
// digit 2 is transmitted as <<-->>
// find the number being transmitted
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    ll n = 0;
    for(char c : s){
        n++;
    }
    string ans = "";
    for (ll i = 0; i < n; i++){
        if(s[i] == '.'){
            ans += '0';
        }
        else if(s[i] == '-'){
            if(s[i + 1] == '.'){
                ans += '1';
            }
            else{
                ans += '2';
            }
            i++;
        }
    }
    cout << ans;
}