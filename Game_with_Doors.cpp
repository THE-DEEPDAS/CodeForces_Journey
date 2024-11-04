// there are 100 rooms and 99 doors ,initially all doors = unlocked
// alice is in room from segment [l , r] and bob is in [L , R]
// we want them to not meet so find minimum number of doors to be closed
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll testcases;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++) {
        ll l, r, L, R;
        cin >> l >> r >> L >> R;

        // Case 1: Non-overlapping intervals
        if (r < L || R < l) {
            cout << "1" << endl;
        }
        // Case 2: Exact match
        else if (l == L && r == R) {
            cout << r - l << endl;
        }
        // Case 3: One interval is a subset of the other
        else if ((l < L && r > R) || (l > L && r < R)) {
            cout << min(r - l, R - L) + 2 << endl;
        }
        // Case 4: Partial overlap with boundaries
        else {
            ll Last = max(l, L);
            ll hirec = min(r, R);
            ll counter = hirec - Last + 2;
            if (l == L) counter--;
            if (r == R) counter--;
            cout << counter << endl;
        }
    }
}
