// we have x , y , n and we want a maximum possible number k such that is lies between
// 0 and n and has remainder  = y when divided by x

typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll x, y, n;
        cin >> x >> y >> n;

        ll k = (n - y) / x;
        ll max_k = k * x + y;
        cout << max_k << endl;
    }
}