// we need to find out substrings of min length 2 and add all the substrings to for string again
// also the first char of ith substring should not match last char of jth one
// so we need 2 different chars with frequency = 2 or 3 different chars
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if(s[0] != s[n - 1]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}