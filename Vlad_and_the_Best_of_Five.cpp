// find the most frequently occuring charachter in the string of 5 numbers
// also there are only 2 letters in the string
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        string s;
        cin >> s;

        ll counter1 = 0, counter2 = 0;
        for (ll i = 0; i < 5; i++)
        {
            if (s[i] == 'A')
            {
                counter1++;
                if (counter1 == 3)
                {
                    cout << "A" << endl;
                    break;
                }
            }

            else
            {
                counter2++;
                if (counter2 == 3)
                {
                    cout << "B" << endl;
                    break;
                }
            }
        }
    }
}
