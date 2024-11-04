// we have a number n, and we have another number ans
// if after rearranging n, the smallest number we can get is ans then print OK, else WRONG_ANSWER
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

// Global setup for fast I/O
struct FastIO
{
    FastIO()
    {
        ios_base::sync_with_stdio(false); // Disable C I/O synchronization
        cin.tie(nullptr);                 // Untie cin and cout for faster input/output
    }
} fast_io_setup; // This will be executed before main()

// Function to return the smallest rearranged number as a string
string smallest_number(string n)
{
    // Sort the digits in ascending order
    sort(n.begin(), n.end());

    // If the smallest digit is '0', move the first non-zero digit to the front
    if (n[0] == '0')
    {
        for (int i = 1; i < n.size(); i++)
        {
            if (n[i] != '0')
            {
                swap(n[0], n[i]); // Move the first non-zero digit to the front
                break;
            }
        }
    }

    return n;
}

int main()
{
    string n;
    cin >> n;

    string ans;
    cin >> ans;

    if (n == "0")
    {
        if (ans == "0")
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "WRONG_ANSWER" << endl;
        }
    }
    else
    {
        if (smallest_number(n) == ans)
            cout << "OK" << endl;
        else
            cout << "WRONG_ANSWER" << endl;
    }
}
