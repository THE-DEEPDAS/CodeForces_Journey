// we have 2 integers x and y
// if we pay a dollars then we can increase or decrease any one integer by 1
// if we pay b dollars then we can increase or decrease both integer by 1
// find min amount to make both = 0
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;

        // if difference is even and b < a then opt for b operation difference times
        // if difference is odd and b < a then opt for b operation diff - 1 times and then a 1 time
        // if difference is odd and b > 2*a then a operation only
        // if difference is even b > 2*a then
        if (b > 2 * a)
        {
            cout << (x + y) * a << endl;
        }
        else
        {
            ll differnce = abs(x - y);
            // so till one reaches 0 we need to choose b only
            ll answer = 0;
            answer = min(x, y) * b;

            answer += differnce * a;
            cout << answer << endl;
        }
    }
}