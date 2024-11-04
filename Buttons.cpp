//derive the formula from giving wrong answer 2 times of testcase and identify the pattern

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n = 0;
    cin >> n;

    long long presses = (n - 1) * n * (n + 1) / 6 + n;

    cout << presses << endl;
}