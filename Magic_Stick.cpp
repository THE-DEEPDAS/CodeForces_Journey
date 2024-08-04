// an even number a will turn to 3*a/2
// number > 1 then number will turn to a - 1
// if both conditions are true then we can choose which to apply
// he wants to make a number Y from X we need to just say is it possible
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll X, Y;
        cin >> X >> Y;

        set<ll> found;

        bool alredy_printed = false;
        while (X < Y)
        {
            if ((X & 1) == 0)
            {
                X = 3 * X / 2;
            }
            else if (X & 1)
            {
                X = X - 1;
            }
            if (found.find(X) == found.end())
            {
                found.insert(X);
            }
            else
            {
                cout << "NO" << endl;
                alredy_printed = true;
                break;
            }
        }

        if (!alredy_printed)
        {
            cout << "YES" << endl;
        }
    }
}