#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO
{
    FastIO()
    {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr);                 // Untie cin and cout for faster input/output
    }
} fast_io_setup; // This will be executed before main()

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, m, r1, r2;
        cin >> n >> m >> r1 >> r2;

        if (r1 > r2)
        {
            swap(r1, r2);
        }

        // first position is 2*(r1 + 1)
        ll ans = 2 * (r1 + 1);
        bool printed = false;
        // second position will be from (r1 + 3, 2*(r1 + 1))
        ll x = (r1 + 3 + r2);
        if (x > n)
        {
            cout << -1 << endl;
            printed = true;
        }
        else
        {
            ans += x;
            ll y = (2 * (r1 + 1) + r2);
            if (y > m)
            {
                cout << -1 << endl;
                printed = true;
            }
            else
            {
                ans += (2 * (r1 + 1) + r2);
            }
        }
        if (!printed)
        {
            cout << ans << endl;
        }
    }
}