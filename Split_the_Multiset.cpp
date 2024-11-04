// what we have is the a single element in the set
// in each turn we can split it into k elements
// then we need to find the number of moves to make all the elements 1's
// so the approach will be we will make (k - 1) 1's and then take the remaining element as new n
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

ll helper(int n, int ans, int k)
{
    if (n <= 1)
        return ans;

    return helper(n - (k - 1), ans + 1, k);
}

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, k;
        cin >> n >> k;

        ll ans = 0;
       ans = helper(n, ans, k);

        cout << ans << endl;
    }
}
