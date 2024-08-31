// given 2 integers l and r . l to r a ++ or a --
// find max value in array after each n operations
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, m;
        cin >> n >> m;

        ll largest = INT_MIN;
        ll largest_index = -1;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > largest)
            {
                largest = a[i];
                largest_index = i;
            }
        }

        char sign;
        ll l, r;
        for (ll i = 0; i < m; i++)
        {
            cin >> sign >> l >> r;
    
            if(l <= largest && largest <= r){
                if(sign == '+'){
                    largest++;
                }
                else{
                    largest--;
                }
                cout << largest << " ";
            }
            else{
                cout << largest << " ";
            }
        }
        cout << endl;
    }
}