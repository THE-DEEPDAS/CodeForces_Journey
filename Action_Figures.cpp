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

        string s;
        cin >> s;

        vector<ll> p0;
        vector<ll> p1;

        for (ll i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                p0.push_back(i);
            else
                p1.push_back(i);
        }

        reverse(p1.begin(), p1.end());

        ll s0 = p0.size() - 1, s1 = p1.size() - 1, t = ((ll)n * (n + 1)) / 2;
        for (ll i = n - 1; i >= 0; i--)
        {
            while (s1 >= 0 && p1[s1] >= i)
                s1--;
            while (s0 >= 0 && p0[s0] >= i)
                s0--;

            if (s[i] == '1')
            {
                if (s0 >= 0)
                {
                    t -= (i + 1);
                    s0--;
                }
                else if (s1 >= 0)
                {
                    t -= (i + 1);
                    s1--;
                }
            }
        }
        cout << t << endl;
    }
}