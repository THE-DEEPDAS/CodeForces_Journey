// we need to make an integer x from doing sigma(a[i] * 2^1)
// so make x from combination of 2's powers into -1, 0 or +1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll x;
        cin >> x;

        vector<ll> result;
        ll power = 0, ans = 0;
        while (ans + pow(2, power) <= x)
        {
            result.push_back(1);
            ans += pow(2, power);
            power++;
        }
        while(ans != x){
            if(ans > x){
                ans -= pow(2, power++);
                result.push_back(-1);
            }
            else{
                ans += pow(2, power++);
                result.push_back(1);
            }
        }

        ll n = result.size();
        cout << n << endl;
        for (ll i = 0; i < n; i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
}