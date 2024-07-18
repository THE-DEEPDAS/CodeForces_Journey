// ith level of pyramid must have i cubes
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int available = 0;
    cin >> available;

    int cubes_used = 0, levels = 0 ,i = 1;
    while (true)
    {
        int cubes_needed = i * (i + 1) / 2; // Sum of first i natural numbers
        if (cubes_used + cubes_needed > available) {
            break;
        }
        cubes_used += cubes_needed;
        levels++;
        i++;
    }
    cout << levels << endl;
}