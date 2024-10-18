// we have a binary string s
// add 1 to one ending and 0 to other end of the string
// we need to find the length of the shortest possible string we could have started with
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

        ll removable = 0;
        for (ll i = 0; i < n / 2; i++){
            if((s[i] == '1' && s[n - i - 1] == '0') || (s[i] == '0' && s[n - i - 1] == '1')){
                removable += 2;
            }
            else
                break;
        }

        cout << n - removable << endl;
    }
}