// f(t): Number of non-empty subsequences of t containing only 0s.
// g(t): Number of non-empty subsequences of t containing at least one 1.
// find the smallest string with minimum |f(t) - g(t)|
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        string s = "1";
        s += string(n - 1, '0');

        cout << s << endl;
    }
}
