#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int presses = 0;
    for (int i = 1; i <= n; i++)
    {
        presses += 3*i - 3;
    }

    cout << presses << endl;
}