// we have array of integers
// we can take 2 adjacent numbers and change their sign
// find the maxiumum sum of array after performing the ops
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        // see we need to change sign when we find 2 negatives in line
        // if positive negative but magnitude of negative is greater than positive ones
        // but a better approach is we change all negatives but if there are odd numbers 
        // of negatives then we will not change the sign of the minimum one
        
        vector<ll> a(n);
        ll sum = 0, negatives = 0;

        for (ll i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] < 0){
                negatives++;
                a[i] = -a[i];
            }
            sum += a[i];
        }

        if(negatives & 1){
            ll min_element_in_array = *min_element(a.begin(), a.end());
            cout << sum - 2 * min_element_in_array << endl;
        }
        else
            cout << sum << endl;
    }

}