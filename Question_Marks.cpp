// n questions, 4n options and each option has n correct answers
// find max score possible
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

ll min(ll x, ll y){
    return x < y ? x : y;
}

int main() {
    ll testcases;
    cin >> testcases;
    
    for (ll testcase = 0; testcase < testcases; testcase++) {
        ll n;
        cin >> n;
        ll char1 = 0, char2 = 0, char3 = 0, char4 = 0;

        for (ll i = 0; i < 4 * n; i++){
            char c;
            cin >> c;
            if(c == 'A'){
                char1++;
            }
            else if(c == 'B'){
                char2++;
            }
            else if(c == 'C'){
                char3++;
            }
            else if(c == 'D')
                char4++;
        }

        cout << min(char1, n) + min(char2, n) + min(char3, n) + min(char4, n) << endl;
    }
}