// see we can split all the permutations into cycles
// also we want to swap 2 elements of "same" cycle so length of each cycle in that permutation should be <= 2
// we can keep spliting cycle by 2 so we can get ans in floor((x - 1) / 2) swaps
// all cycles are independent, so the answer for the initial task is the sum of answers for every cycle.
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

        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        bool visited[n + 1];                // Array to track which elements have been visited
        memset(visited, 0, sizeof visited); // Initialize all elements as unvisited
        ll cycleCount = 0;                 // Count for a specific property related to cycle lengths

        for (ll start = 1; start <= n; start++)
        {
            if (!visited[start])
            { // If this element hasn't been visited, start a new cycle
                ll current = start;
                ll cycleLength = 0; // To keep track of the current cycle length

                // Traverse the cycle starting from 'current'
                while (!visited[current])
                {
                    cycleLength++;           // Increment length for each element in the cycle
                    visited[current] = true; // Mark this element as visited
                    current = a[current];    // Move to the next element in the cycle
                }

                cycleCount += (cycleLength - 1) / 2;
            }
        }

        cout << cycleCount << '\n';
    }
}