#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int total_ml = k * l;
    int total_slices = c * d;
    int total_salt = p;

    // possible number of toasts from drink constraints
    int t_drink = total_ml / (n * nl);

    // possible number of toasts from lime constraints
    int t_lime = total_slices / n;

    // possible number of toasts from salt constraints
    int t_salt = total_salt / (n * np);

    // the minimum number of toasts each friend can make
    int min_toasts = min({t_drink, t_lime, t_salt});

    cout << min_toasts << endl;
}
