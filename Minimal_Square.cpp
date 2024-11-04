typedef long long ll;
#include <bits/stdc++.h>

using namespace std;
ll minimum(ll a, ll b){
    if(a <= b) return a;
    else if(a >= b) return b;
}
ll maximum(ll a, ll b){
    if(a > b) return a;
    else return b;
}

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll a , b;
        cin >> a >> b;

        ll mini = minimum(a, b);
        ll maxi = maximum(a, b);

        if(mini + mini > maxi){
            cout << (mini + mini) * (mini + mini) << endl;
            continue;
        }

        else{
            cout << (maxi * maxi) << endl;
        }
    }
}