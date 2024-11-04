// we have two integers n and x
// find triplets such that ab + bc + ca <= n and a + b + c <= x
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, x;
        cin >> n >> x;

        ll count = 0;
        for(ll a = 1; a <= x; a++){
            for(ll b = 1; b <= x; b++){
                for(ll c = 1; c <= x; c++){
                    if(a + b + c <= x && (a*b + b*c + c*a <= n)){
                        count++;
                    }
                }
            }
        }
        cout << count << endl;

    }
    */

   // This didn't work due to Time complexity
   ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n, x;
        cin >> n >> x;

        ll count = 0;

        for (ll a = 1; a <= min(n, x); a++) {
            for (ll b = 1; a * b <= n and a + b <= x; b++) {
                // Compute the maximum possible value of c given a and b
                ll maxC = min((n - a * b) / (a + b), x - (a + b));
                
                count += maxC;
            }
        }

        cout << count << endl;
    }
}