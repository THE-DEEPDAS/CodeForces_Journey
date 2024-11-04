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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        ll median_index = (n - 1) / 2, result = 1;

        // so the logic is that if the median is equal to the next element, then median becomes the element which we will increase
        // and as we increase so index will also increase
        while (median_index < n - 1 && arr[median_index] == arr[median_index + 1])
        {
            median_index += 1;
            result += 1;
        }
        cout << result << endl;
    }
}
