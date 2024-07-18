// we have a , b , n 
//we have to make either of a or b > n and return the minimum steps to do so
//only operations allowed are a += b or b += a
#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    while (testcases--) {
        int a, b, n;
        cin >> a >> b >> n;

        // Ensure a is the smaller value and b is the larger value
        if (a > b) swap(a, b);

        int steps = 0;

        // Keep adding the smaller value to the larger one until either exceeds n
        while (b <= n) {
            a += b; // Add the smaller value to the larger one
            steps++;
            if (a > n) break; // If the new value of a exceeds n, break the loop
            swap(a, b); // Swap the values to maintain a as the smaller and b as the larger
        }

        cout << steps << endl;
    }
}
