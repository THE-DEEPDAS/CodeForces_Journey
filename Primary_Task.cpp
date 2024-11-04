// wrote t integers and forgot one integer n of the form 10^x ; x>=2
// he wrote 10^19 like 1019
// check if given integer can be important integer which he forgot
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll a;
        cin >> a;

        string s = to_string(a);
        ll n = s.size();
        if(s[2] == '0' || s[0] != '1' || s[1] != '0'){
            cout << "No" << endl;
            continue;
        }
        ll power = 0;
        for(ll i = 2; i < n; i++){
            power = (power * 10) + (s[i] - '0');
        }
        if(power >= 2){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}