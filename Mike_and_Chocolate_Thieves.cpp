// if one thief takes some n chocolates then next one will take k * n chocolates
// thieves bag can contain maximum of n chocolates and there are 4 thieves
// the number of way they can take chocolates is m
// find the smallest possible values of n
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll countWays(ll n)
{
    ll count = 0;

    for (ll k = 2; k * k * k <= n; k++)
    {
        count += n / (k * k * k);
    }

    return count;
}

int main()
{
    ll m;
    cin >> m;

    ll left = 1, right = 1e18;
    // just so left and right should not be neighbours
    while (left < right - 1)
    {
        ll mid = left + (right - left) / 2;

        if (countWays(mid) >= m)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    if (countWays(right) == m)
    {
        cout << right << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
