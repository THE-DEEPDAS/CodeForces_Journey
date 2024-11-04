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
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        ll ans = n, left = 1, right = n;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            bool found = false;

            if (mid == 1)
            {
                ans = min(ans, n - 1);
                left = mid + 1;
                continue;
            }

            for (ll i = 0; i + mid - 1 < n; i++)
            {
                ll x = a[i] + a[i + 1];
                if (x > a[i + mid - 1])
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                ans = min(ans, n - mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << ans << endl;
    }
}