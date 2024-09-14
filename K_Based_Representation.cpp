#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll k;
        cin >> k;

        ll num;
        cin >> num;

        vector<ll> a(num);
        for (ll i = 0; i < num; i++)
            cin >> a[i];

        for (ll i = 0; i < num; i++)
        {
            ll used = 0;
            ll k_mult = k;
            ll cnt = 0;
            while (a[i] / k_mult >= 1)
            {
                k_mult *= k;
                cnt++;
            }
            ll rem = a[i] % k_mult;
            used += cnt;
            ll temp = 0;
            if (rem != 0)
            {
                used += rem / k;
                temp = rem / k;
            }

            ll final_rem = rem - (temp * k);
            if (final_rem != 0)
            {
                used += (final_rem * 2);
            }
            if (used <= 10)
                cout << "yes" << endl;
            else
            {
                used = 0;
                k_mult = k;
                cnt = 0;
                while(a[i] / k_mult != 0){
                    k_mult *= k;
                    cnt++;
                }
                used += cnt;
                rem = k_mult - a[i];
                temp = 0;
                if (rem != 0){
                    used += rem / k;
                    temp = rem / k;
                }
                final_rem = rem - (temp * k);
                if (final_rem != 0){
                    used += (final_rem * 2);
                }
                if (used <= 10){
                    cout << "yes" << endl;
                }
                else{
                    cout << "No" << endl;
                }
            }
        }
    }
}