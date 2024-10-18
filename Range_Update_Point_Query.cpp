// we have array of integers and have to answer q queries
// for 1 l r, update all nums from l to r with sum of digits in those nums
// 2 x then print the value of a[x]
// indexes are given in 1 based indexing
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Helper function to calculate the sum of digits
ll sum_of_digits(ll num)
{
    ll sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, q;
        cin >> n >> q;

        vector<ll> a(n);
        unordered_map<ll, ll> digit_sum_map; // Map to store sum of digits for each number

        // Input the array and store the sum of digits for each number in the map
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            digit_sum_map[a[i]] = a[i]; // Store the original number
        }

        // Flag to keep track of whether we have performed the sum of digits operation
        vector<bool> updated(n, false);

        while (q--)
        {
            ll type;
            cin >> type;

            if (type == 1)
            {
                // Query type 1: "1 l r" - Update elements from l to r to sum of digits
                ll l, r;
                cin >> l >> r;
                l--;
                r--; // Convert to 0-based indexing

                for (ll i = l; i <= r; i++)
                {
                    if (!updated[i])
                    {
                        // Calculate the sum of digits
                        ll new_value = sum_of_digits(a[i]);
                        a[i] = new_value; // Update the array with the sum of digits
                        digit_sum_map[a[i]] = new_value; // Update the map with the new value
                        updated[i] = true; // Mark this element as updated
                    }
                }
            }
            else if (type == 2)
            {
                // Query type 2: "2 x" - Print the value at position x
                ll x;
                cin >> x;
                x--; // Convert to 0-based indexing
                cout << a[x] << endl;
            }
        }
    }
}
