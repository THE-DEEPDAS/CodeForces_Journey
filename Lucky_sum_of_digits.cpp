// find a lucky number whose sum of digits is given to us and we need to find minimum lucky number
// the main problem is faced when if we find max sevens and then number is not divisible by 4
// but in reality takin one or two 7's less and increasing 4's can make a valid sum
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll number;
    cin >> number;

    string result = "";
    
    // Find the maximum number of 7s we can use
    ll max_sevens = number / 7;
    bool found = false;

    // Iterate from maximum number of 7s down to 0
    for (ll sevens = max_sevens; sevens >= 0; --sevens)
    {
        ll remaining_sum = number - sevens * 7;
        // Check if the remaining sum can be exactly filled with 4s(this is main step)
        if (remaining_sum % 4 == 0)
        {
            ll fours = remaining_sum / 4;
            // Generate the number by appending sevens and fours
            result = string(fours, '4') + string(sevens, '7');
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << result;
    }
    else
    {
        cout << "-1";
    }
}