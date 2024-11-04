// n people(1 to n) want to present the slideshow of m slides
// when a person in front if finished with presenting then he/she can go to any place without changing others' position
// there is another array b and is considered good if bi person presents ith slide
// in each query the boss will set b(si) = ti, where si = slide and ti = member
// for each q + 1 states tell if the array is good
// for easy version q = 0
// print YA if presentation is good else TIDAK

/* TIME LIMIT EXCEEDS ON 30TH TESTCASE :(
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

bool Good(vector<ll> &a, vector<ll> &b, ll m)
{
    // so traverse through each slide and maintain a vector of who has arrived to present
    // now if b[i] is among anyone who has presented then it is good only
    // if b[i] is not among anyone who has presented then it is not good
    // Track who has presented by using a set for efficient look-up
    // Track pending members who have presented before and can present again.
         unordered_set<ll> pending;
        bool isGood = true;
        ll idx = 0;  // Points to the next person in `a` who hasn't yet presented.
 
        for (ll i = 0; i < m && idx < a.size(); i++) {
            if (b[i] == a[idx]) {  // `b[i]` is the next in the initial sequence `a`.
                pending.insert(a[idx]);  // Add to pending members.
                idx++;  // Move to the next person in `a`.
            } else if (pending.count(b[i]) == 0) {  // `b[i]` is neither the next person in `a` nor pending.
                isGood = false;
                break;
            }
            // If `b[i]` is in `pending`, it's already eligible to present.
        }
        return isGood;
}

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n, m, q;
        cin >> n >> m >> q;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<ll> b(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        if(Good(a, b, m)){
            cout << "YA" << endl;
        }
        else{
            cout << "TIDAK" << endl;
        }
        while (q--)
        {
            ll idx, val;
            cin >> idx >> val;
            b[idx - 1] = val;
            if (Good(a, b, m))
                cout << "YA" << endl;
            else
                cout << "TIDAK" << endl;
        }
    }
}
*/