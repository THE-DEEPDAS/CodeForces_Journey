// we need to find answer of 2 same lengthed number such that answer's bit is 1 if bits on same position differ 
// else the answer's bit is 0
// don't remove leading 0's
// string is only of 0's and 1's
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;

    ll n = str1.size();
    string ans = "";
    for (ll i = 0; i < n; i++){
        if(str1[i] == str2[i])
            ans += '0';
        else ans += '1';
    }

    cout << ans;
}