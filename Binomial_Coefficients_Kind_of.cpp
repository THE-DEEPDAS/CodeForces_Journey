#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
typedef long long ll;

int C[MAXN][101];

void precompute_wrong_binomial() {
    for (int n = 0; n < MAXN; n++) {
        C[n][0] = 1; 
        if (n < 101) C[n][n] = 1;  
        for (int k = 1; k < n && k < 101; k++) {
            C[n][k] = (C[n][k - 1] + C[n - 1][k - 1]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_wrong_binomial();

    int t;
    cin >> t;
    vector<int> n(t), k(t);
    for (int i = 0; i < t; i++) {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < t; i++) {
        cout << C[n[i]][k[i]] << endl;
    }

    return 0;
}
