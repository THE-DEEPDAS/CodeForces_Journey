// given two integers a and b
// in one move choose an integer k from 1 to 10 and add it or subtract it from a
// find minimum number of moves to get b from a
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll a, b;
        cin >> a >> b;

        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        
        ll diff = abs(a - b);
        ll moves = diff % 10 == 0 ? diff / 10 : (diff / 10) + 1;
        cout << moves << endl;
    }
}