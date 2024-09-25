/*
   Problem: You are given an array `a` of `n` integers.

   You need to perform a series of operations to make all elements in the array equal to 0.

   Operation Steps:
   1. Choose an integer `x` (0 ≤ x ≤ 10^9).
   2. Replace each element `ai` with `|ai - x|` where |v| denotes the absolute value of v.

   Goal:
   - Perform at most 40 operations to make all elements of the array equal to 0.
   - If it’s possible, output the number of operations and the sequence of `x` values used in each operation.
   - If it’s impossible to make all elements 0 within 40 operations, output `-1`.

   Input Format:
   - The first line contains a single integer `t` (1 ≤ t ≤ 10^4) — the number of test cases.
   - For each test case:
       - The first line contains the integer `n` (1 ≤ n ≤ 2 * 10^5) — the length of the array.
       - The second line contains `n` integers, the elements of the array `a`.

   Output Format:
   - For each test case:
       - Output -1 if it's impossible to make all elements 0 within 40 operations.
       - Otherwise, output the number of operations and the sequence of `x` values used.

   Constraints:
   - Sum of n over all test cases does not exceed 2 * 10^5.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to find the median of a sorted array (Unused in current solution but included for reference)
ll find_median(vector<ll> &arr)
{
    sort(arr.begin(), arr.end());
    ll n = arr.size();
    return arr[n / 2]; // The median in a sorted array (0-based index)
}

int main()
{
    ll testcases;
    cin >> testcases; // Input number of test cases

    // Loop through each test case
    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;  // `n` is the length of the array, `m` is an unused variable in the problem
        cin >> n;
        bool pairity_same = true; // A flag to check if all elements have the same parity

        vector<ll> a(n);  // Array to store the elements of the current test case
        cin >> a[0];
        ll parity = a[0] % 2;
        for (ll i = 1; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 != parity)  // If any element has different parity, set flag to false
            {
                pairity_same = false;
            }
        }

        // If array has mixed parity, it's impossible to reduce all elements to 0, so output -1
        if (!pairity_same)
        {
            cout << -1 << endl;
        }
        else
        {
            // If all elements have the same parity, perform the operations
            cout << 31 << endl;  // We output 31 steps (this is a known pattern to handle same-parity arrays)
            
            // Loop through 30 steps, adjusting the array using powers of 2 (1 << x)
            for (int x = 29; x >= 0; x--)
            {
                ll this_num = (1 << x);
                cout << this_num << " ";  // Output the chosen `x` value, which is powers of 2: 2^29, 2^28, ..., 2^0
                
                // Adjust each element of the array by replacing ai with |ai - (1 << x)|
                for (auto &q : a)
                    q = abs(q - this_num);
            }
            cout << a[0] << endl;  // Output the last element of the array (should be 0 after final operation)
        }
    }
}
