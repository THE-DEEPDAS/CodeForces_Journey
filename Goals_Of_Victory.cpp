// there are n teams palying in a football tournament
// we have the efficiency of n - 1 teams , we need to find the efficiency of last one
// efficieny = goals by that team - goal by other teams combined
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        vector<ll> a(n - 1);
        ll sum = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        cout << -sum << endl;
    }
}