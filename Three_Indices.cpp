// we need to find 3 indices i, j and k such that p[i] < p[j] and p[j] > p[k] and i < j < k
// also given that p is a permutation
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

        bool check = false;

        vector<ll> permutation(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> permutation[i];
        }

        for (ll i = 0; i < n - 2; i++)
        {

            if (permutation[i] < permutation[i + 1] && permutation[i + 1] > permutation[i + 2])
            {
                check = true;
                cout << "YES" << endl;
                // please take care that indexing is 1 based 
                cout << i + 1 << " " << i + 2 << " " << i + 3 << endl;
                break;
            }
        }

        if (!check)
        {
            cout << "NO" << endl;
        }
    }
}