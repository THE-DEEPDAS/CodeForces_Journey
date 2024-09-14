#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    while(testcases--){
    ll n;
    cin >> n;

    string ans = "";
    for (ll i = 0; i < n; i++){
        if(i % 5 == 0)
            ans.push_back('a');
        else if(i % 5 == 1)
            ans.push_back('e');
        else if(i % 5 == 2)
            ans.push_back('i');
        else if(i % 5 == 3)
            ans.push_back('o');
        else
            ans.push_back('u');
    }

    sort(ans.begin(), ans.end());
    cout << ans << endl;
    }
}