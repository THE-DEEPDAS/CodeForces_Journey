// we need to divide a number w into 2 even numbers(may not be equal)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll w;
    cin >> w;

    if (w % 4 == 0 || (w > 4 && w % 2 == 0))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}