// we have a ,b ,c, d in non-decreasing order
// task is to find out 3 numbers x ,y ,z which are between(if possible) of a,b and b,c and c,d.
// also x,y,z are sides of traingle and we want a triangle whose area > 0
// so main thing is sum of 2 sides > one side always follows
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
        for (ll i = 0; i < 3; i++)
        {
            ll diff = nums[i + 1] - nums[i];
            if (diff != 0 && diff != 1)
            {
                ans[i] = nums[i + 1] - 1;
            }
            else
            {
                ans[i] = nums[i + 1];
            }
        }

        if(ans[0] + ans[1] <= ans[2]){
            if(ans[0] < nums[1]){
                ans[0] = nums[1];
            }
            else{
                ans[1] = nums[2];
            }
        }

        for (ll i = 0; i < 3; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}