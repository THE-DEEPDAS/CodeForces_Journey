// we have lost the string but we have the trace of it
// explaination of trace
// abracadabra is the array [0,0,0,1,0,2,0,3,1,1,4]
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO
{
    FastIO()
    {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr);                 // Untie cin and cout for faster input/output
    }
} fast_io_setup; // This will be executed before main()

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        char c = 'a';
        char d = 'a';
        string s = "";
        for (ll i = 0; i < n; i++){
            if(a[i] == 0){
                s += c;
                c++;
            }
            else if(a[i] == 1){
                s += d;
                d++;
            }
            else{
                s += 'a';
            }
        }

        cout << s << endl;
    }
}