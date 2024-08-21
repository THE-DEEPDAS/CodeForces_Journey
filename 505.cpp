// binary matrix is called good if every even length square sub-matrix has an odd number of ones.
// n row and m column matrix and we want min cells to be changed to make it good
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll n, m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
}