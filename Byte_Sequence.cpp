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

        if (n == 3)
        {
            cout << "2 1 3" << "\n";
        }
        else if (n == 2)
        {
            cout << "2 2" << "\n";
        }
        else
        {
            if (n % 2 == 0)
            {
                for (ll i = 1; i <= n - 2; i++)
                {
                    cout << 1 << " ";
                }
                cout << n - (n - 2) << " ";
                cout << n << "\n";
            }
            else{
                for (ll i = 1; i <= n - 3; i++){
                    cout << 1 << " ";
                }
                cout << "2 1" << " ";
                cout << n << "\n";
            }
        }
    }
}