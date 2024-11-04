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
        ll n, q;
        cin >> n >> q;

        vector<char> nums1(n);
        vector<char> nums2(n);

        // Prefix sums for character frequencies
        vector<vector<ll>> v1(n + 1, vector<ll>(26, 0));
        vector<vector<ll>> v2(n + 1, vector<ll>(26, 0));

        for (ll i = 0; i < n; i++)
        {
            cin >> nums1[i];
            for (int c = 0; c < 26; c++)
            {
                v1[i + 1][c] = v1[i][c];
            }
            v1[i + 1][nums1[i] - 'a']++;
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> nums2[i];
            for (int c = 0; c < 26; c++)
            {
                v2[i + 1][c] = v2[i][c];
            }
            v2[i + 1][nums2[i] - 'a']++;
        }

        while (q--)
        {
            ll start, end;
            cin >> start >> end;

            ll diff = 0;
            for (int c = 0; c < 26; c++)
            {
                ll val1 = v1[end][c] - v1[start - 1][c];
                ll val2 = v2[end][c] - v2[start - 1][c];

                diff += abs(val1 - val2);
            }
            cout << diff / 2 << endl;
        }
    }
}
