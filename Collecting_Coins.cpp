// we have n coins
// 3 people have initially a , b , c coins
// we want to find can we distribute n coins such that all have equal coins
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        bool checked = false;
        vector<ll> coins(3);
        ll n;
        cin >> coins[0] >> coins[1] >> coins[2] >> n;

        sort(coins.begin(), coins.end());

        while (n > 0)
        {
            int d1 = coins[2] - coins[0];
            int d2 = coins[2] - coins[1];
            if (d1 == 0 && d2 == 0)
            {
                if (n % 3 == 0)
                {
                    cout << "YES" << endl;
                    checked = true;
                    break;
                }
                else
                {
                    cout << "NO" << endl;
                    checked = true;
                    break;
                }
            }
            n -= (d1 + d2);
            coins[0] += d1;
            coins[1] += d2;
        }

        if (n == 0 && (!checked))
        {
            cout << "YES" << endl;
        }
        else if (!checked)
        {
            cout << "NO" << endl;
        }
    }
}