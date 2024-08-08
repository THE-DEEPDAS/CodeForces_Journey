// appartment number is n
// first floor has 2 appartments and all others = x
// find the floor of petaya

typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, x;
        cin >> n >> x;

        if (n <= 2)
        {
            cout << 1 << endl;
            continue;
        }
        else{
            n-=2;
            cout << ceil(double(n) / x) + 1 << endl;
        }
    }
}