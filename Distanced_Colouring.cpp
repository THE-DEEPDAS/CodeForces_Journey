// we have a n * m grid and a magic number k
// we can colour the coordinates (x1, y1) and (x2, y2) with same colour 
// but if max(|x2 - x1|,|y2 - y1|) >= k
// find min colours to colour all the elements of grid
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fast_IO() {
    // Synchronize C++ streams with C streams
    ios::sync_with_stdio(false);
    // Untie cin from cout to avoid flushing cout before cin
    cin.tie(nullptr);
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, m, k;
        cin >> n >> m >> k;

        if(k > max(n, m)){
            cout << n * m << endl;
            continue;
        }

        cout << min(min(n, m), k) * k << endl;
    }
}