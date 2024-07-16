// if last digit is non-zero num --
// if last digit is zero num /= 10
// all these only for 2 or more digit number
// n number and k times subtraction
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 0;
    cin >> number;

    int k = 0;
    cin >> k;
    while (number > 0 && k > 0)
    {
        int last_digit = number % 10;
        if (last_digit != 0)
        {
            number--;
        }
        else
        {
            number /= 10;
        }
        k--;
    }

    cout << number << endl;
}