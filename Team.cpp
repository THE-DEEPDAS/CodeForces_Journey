// there are 3 participants , team will write the solution of a problem only if 2 of them are sure
// about the correctness. find the total problems that will be solved
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    vector<ll> p1(n);
    vector<ll> p2(n);
    vector<ll> p3(n);

    ll count_in_favour = 0, ans = 0;

    for (ll i = 0; i < n; i++){
        cin >> p1[i] >> p2[i] >> p3[i];
        count_in_favour = 0;
        if (p1[i] == 1)
            count_in_favour++;
        if (p2[i] == 1)
            count_in_favour++;
        if (p3[i] == 1)
            count_in_favour++;
        if (count_in_favour >= 2)
        {
            ans++;
        }
    }

    cout << ans;
}