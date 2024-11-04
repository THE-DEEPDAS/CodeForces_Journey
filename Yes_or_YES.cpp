// we have a string of 3 digits check if it is yes
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if(s == "yes")
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}