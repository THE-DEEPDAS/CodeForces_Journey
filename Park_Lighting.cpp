// park has n rows and m columns
// each lantern lights up 2 parks in vicinity and we can place lantern on center of street only
// find minimum number of lanterns to light up whole park

typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, m;
        cin >> n >> m;

        // if(m == 1){
        //     // If there is only one row, then 
        //     ll ans = (n & 1) ? (n + 1) / 2 : n / 2;
        //     cout << ans << endl;
        // }
        // else if ((m & 1) && (n & 1)){
        //     // so if both are odd then formula becomes (m - 1) * n / 2 + (n + 1) / 2 so laqst is done
        //     // separately in suchj a way that we place lights on horizontal rows
        //     cout << (m * n + 1) / 2 << endl;
        // }
            
        // else{
        //     if(m & 1) m++;
        //     cout << (m / 2) * n << endl;
        // }

        // This is the base number of lanterns needed if the total area is even.
        ll ans = (n * m) / 2;

        // if the total number of cells is odd. If so, it adds one more lantern
        // to account for the extra cell that doesn't fit into the base calculation.
        if((n * m) % 2) ans++;

        cout << ans << endl;
    }
}