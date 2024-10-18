// we have an array of n integers, when there is only 1 element left, game ends
// in each turn we take 2 integers i and j and replace ai, aj by floor((ai + aj) / 2) * 2
// masha tries to maximise the final number and olya tries to minimise
// find the last number standing and masha goes first
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

        vector<ll> odds;
        vector<ll> evens;
        ll num;
        for (ll i = 0; i < n; i++)
        {
            cin >> num;
            if (num % 2 == 0)
            {
                evens.push_back(num);
            }
            else
                odds.push_back(num);
        }

        // to maximise final number we take odd-even pair.
        // to minimise final number we take odd-odd or even-even pair.
        ll odd_size = odds.size(), even_size = evens.size();
        for (ll i = 0; i < n - 1; i++)
        {
            if (i % 2 == 0 && odd_size && even_size)
            {
                ll temp_num = ((odds.back() + evens.back()) / 2) * 2; // Use back() to access the last element
                odds.pop_back();                                      // Then pop the last element
                evens.pop_back();                                     // Then pop the last element
                odd_size--;
                even_size--;
                if (temp_num % 2 == 0)
                {
                    evens.push_back(temp_num);
                }
                else
                    odds.push_back(temp_num);
            }
            else
            {
                if (even_size < odd_size)
                {
                    ll temp1 = evens.back();
                    evens.pop_back();
                    temp1 += evens.back();
                    evens.pop_back();
                    temp1 /= 2;
                    temp1 *= 2;
                    if (temp1 % 2 == 0)
                    {
                        evens.push_back(temp1);
                    }
                    else
                        odds.push_back(temp1);
                }
                else
                {
                    ll temp1 = odds.back();
                    odds.pop_back();
                    temp1 += odds.back();
                    odds.pop_back();
                    temp1 /= 2;
                    temp1 *= 2;
                    if (temp1 % 2 == 0)
                    {
                        evens.push_back(temp1);
                    }
                    else
                        odds.push_back(temp1);
                }
            }
        }
        
    }
}
