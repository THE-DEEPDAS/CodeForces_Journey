#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FastIO
{
    FastIO()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        vector<vector<ll>> a(n, vector<ll>(n));
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                cin >> a[i][j];

        ll ans = 0;

        for (ll col = n - 1; col >= 0; col--)
        {
            ll maxNeg = 0;
            bool hasNeg = false;
            for (ll i = 0, j = col; i < n && j < n; i++, j++)
            {
                if (a[i][j] < 0)
                {
                    maxNeg = max(maxNeg, -a[i][j]);
                    hasNeg = true;
                }
            }
            if (hasNeg)
                ans += maxNeg;
        }

        for (ll row = 1; row < n; row++)
        {
            ll maxNeg = 0;
            bool hasNeg = false;
            for (ll i = row, j = 0; i < n && j < n; i++, j++)
            {
                if (a[i][j] < 0)
                {
                    maxNeg = max(maxNeg, -a[i][j]);
                    hasNeg = true;
                }
            }
            if (hasNeg)
                ans += maxNeg;
        }

        cout << ans << "\n";
    }
}