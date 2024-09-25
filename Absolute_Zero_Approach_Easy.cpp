#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to compute the average of the minimum and maximum elements
ll average_min_max(const vector<ll> &arr)
{
    ll min_element = arr[0];
    ll max_element = arr[0];

    // Traverse the array to find the min and max elements
    for (ll i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < min_element)
        {
            min_element = arr[i];
        }
        if (arr[i] > max_element)
        {
            max_element = arr[i];
        }
    }

    // Return the average of the minimum and maximum elements
    return (min_element + max_element) / 2;
}

int main()
{
    ll t;
    cin >> t;  // Read the number of test cases

    while (t--)
    {
        ll n;
        cin >> n;  // Read the size of the array

        vector<ll> a(n);  // Array to store the elements
        cin >> a[0];  // Read the first element
        ll parity = a[0] % 2;  // Store the parity (odd or even) of the first element
        bool pairity_same = true;  // Flag to check if all elements have the same parity

        // Check if all elements have the same parity
        for (ll i = 1; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 != parity)  // If any element has a different parity, set the flag to false
            {
                pairity_same = false;
            }
        }

        // If all elements do not have the same parity, output -1
        if (!pairity_same)
        {
            cout << -1 << endl;
        }
        else
        {
            ll steps = 0;  // Count the number of operations
            vector<ll> result;  // Store the sequence of averages used in each step
            bool all_zeros = false;  // Flag to check if all elements become zero

            // Loop to perform the operation (maximum 40 steps)
            while (steps <= 40)
            {
                ll avg = average_min_max(a);  // Compute the average of min and max elements
                result.push_back(avg);  // Store the average value used in this step
    
                bool all_zero_now = true;  // Flag to check if all elements become zero in this step

                // Replace each element with |element - avg|
                for (ll i = 0; i < n; i++)
                {
                    a[i] = abs(a[i] - avg);  // Transform the array
                    if (a[i] != 0)
                        all_zero_now = false;  // If any element is non-zero, set the flag to false
                }

                steps++;  // Increment the step counter

                // If all elements are zero, break out of the loop
                if (all_zero_now)
                {
                    all_zeros = true;
                    break;
                }
            }

            // Output the result
            if (all_zeros)
            {
                cout << steps << endl;  // Output the number of steps taken
                for (ll num : result)
                {
                    cout << num << " ";  // Output the sequence of average values used
                }
                cout << endl;
            }
            else
            {
                cout << -1 << endl;  // If it’s not possible to make all elements zero in 40 steps, output -1
            }
        }
    }
}
