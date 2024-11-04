// 5 to 9 = large numbers
// positive number is large if all numbers are large
// given a number n, can it be sum of 2 large numbers
// so logic is length of the 2 should be n - 1 as 1 will be carried over always(num > 5)
// also in unit digit, carry = 0 so range = 0 to 8, else 1 to 9
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

        n = n - n % 10 + (n % 10 + 1) % 10;
        bool printed = false;
        while (n > 9)
        {
            if (n % 10 == 0)
            {
                cout << "NO\n";
                printed = true;
                break;
            }
            n /= 10;
        }

        if (!printed)
        {
            if (n == 1)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
}
