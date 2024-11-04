// we have a boolean string
// alice wants the output to be true
// bob wants to make it false
// print yes if alice wins else no
// so if 1st or last element is 1 she can always win or else she needs to have consecutive 1s
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool AliceWins(string &s){
    ll n = s.size();
    if (s[0] == '1' || s[n - 1] == '1') {
        return true;
    }

    for (ll i = 1; i < n; i++) {
        if (s[i] == '1' && s[i - 1] == '1') {
            return true;
        }
    }
    
    return false;
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        if(AliceWins(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
