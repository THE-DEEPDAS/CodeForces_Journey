// we have a ,b ,c, d in non-decreasing order
// task is to find out 3 numbers x ,y ,z which are between(if possible) of a,b and b,c and c,d.
// also x,y,z are sides of traingle and we want a triangle whose area > 0
// so main thing is sum of 2 sides > one side always follows
// so we have 4 numbers and we want 3 numbers such that sum od 2 > single so last number should be minimal and first 2 should be maximal

typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        vector<ll> nums(4);
        for (ll i = 0; i < 4; i++)
        {
            cin >> nums[i];
        }

        vector<ll> ans(3);
        ans[0] = nums[1];
        ans[1] = nums[2];
        ans[2] = nums[2];
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
}