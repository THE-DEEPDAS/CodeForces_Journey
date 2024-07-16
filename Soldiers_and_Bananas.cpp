// w bananas to be taken and ik for each banana
// he has n dollars ,how much to borrow
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w = 0, k = 0, n = 0;
    cin >> k >> n >> w;

    int total_cost = 0;
    int i = 1;
    while (w--)
    {
        total_cost += i * k;
        i++;
    }
    if (total_cost - n >= 0)
        cout << total_cost - n << endl;

    else
        cout << 0 << endl;
}