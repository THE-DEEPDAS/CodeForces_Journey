// we need to fins the minimum length of substring which needs to be painted white to make all white
// white = W and black = B
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

        ll min_count = 0, max_count = 0;
        bool found = false;
        for (ll i = 0; i < n; i++)
        {
            if (!found && s[i] == 'B')
            {
                found = true;
                min_count = i;
                max_count = i;
            }
            else if (s[i] == 'B')
            {
                max_count = i;
            }
        }

        ll ans = max_count - min_count + 1;
        
        cout << ans << endl;
    }
}