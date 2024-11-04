// we have 2 elevators one is at floor a and can come to floor 1
// and other will first go to floor c and is at b then will come to 1
// find the faster lift
// return 3 if they come at same time
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr); // Untie cin and cout for faster input/output
    }
} fast_io_setup; // This will be executed before main()

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b, c;
        cin >> a >> b >> c;

        ll time_by_elevator_1 = abs(a - 1);
        ll time_by_elevator_2 = abs(c - b) + abs(c - 1);
        if(time_by_elevator_1 == time_by_elevator_2) cout << 3 << "\n";
        else if(time_by_elevator_1 < time_by_elevator_2)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}