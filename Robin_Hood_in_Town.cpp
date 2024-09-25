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

bool possible(const vector<ll> &a, ll total_sum, ll n, ll x)
{
    ll new_total_sum = total_sum + x;
    double half_average = double(new_total_sum) / (2 * n);

    ll unhappy_count = 0;
    for (ll wealth : a)
    {
        if (wealth < half_average)
        {
            unhappy_count++;
        }
    }
    return unhappy_count > n / 2;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);

        ll total_sum = 0, max_a = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            total_sum += a[i];
            max_a = max(max_a, a[i]);
        }

        if (n <= 2)
            cout << -1 << endl;

        else
        {
            ll left = 0, right = 1e18, ans = -1;
            while (left <= right)
            {
                ll mid = left + (right - left) / 2;
                if (possible(a, total_sum, n, mid))
                {
                    ans = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            cout << ans << endl;
        }
    }
}
