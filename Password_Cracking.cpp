// see here we need to find a password of length n which is a string of 0's and 1's
// also it is a ge like structure that we will ask if this is a substring and computer will reply with a yes or no
// approach: start with empty substring and do s + 0, s + 1 and if none is a substring it means s is suffix
// so now we will do 0 + s and  1 + s and check which is the answer
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

bool ask(string t)
{
    cout << "? " << t << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        string s;
        while (s.size() < n)
        {
            if (ask(s + "0"))
            {
                s += "0";
            }
            else if (ask(s + "1"))
            {
                s += "1";
            }
            else
            {
                break;
            }
        }
        while(s.size() < n){
            if(ask("0" + s)){
                s = "0" + s;
            }
            else
                s = "1" + s;
        }

        cout << "! " << s << endl;
    }
}