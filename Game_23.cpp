// we want to make a number m from n
// we can multiply n by 2 or 3 only
// print the number of moves to do so

typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    // initial checks to avoid going ahead
    if (n == m)
    {
        cout << 0 << endl;
        exit(0);
    }
    else if ((n < 0 || m < 0) || (n > m))
    {
        cout << -1 << endl;
        exit(0);
    }

    // using binary lifting to find the power of 2 that is less than or equal to m
    ll quotient = m / n;
    if (m % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int moves = 0;
    // finding the 2's which can help in making m
    while (quotient % 2 == 0)
    {
        quotient /= 2;
        moves++;
    }
    // finding the 3's which can help in making
    while (quotient % 3 == 0)
    {
        quotient /= 3;
        moves++;
    }

    if (quotient == 1)
    {
        cout << moves << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}