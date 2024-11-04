// given a string s we need to change the charachters to one charachter before or after
// but in alphabetical order
// can we make a palindromic string by this conversion?
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;
    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll length = 0;
        cin >> length;
        string s;
        cin >> s;

        vector<char> from_start;
        vector<char> from_end;
        for (ll i = 0; i < length / 2; i++)
        {
            from_start.push_back(s[i]);
        }
        for (ll i = length - 1; i >= length / 2; i--)
        {
            from_end.push_back(s[i]);
        }

        ll size_vector = from_start.size();
        bool valid = true;
        for (int i = 0; i < size_vector; i++)
        {
            if (abs(from_start[i] - from_end[i]) == 2 || abs(from_start[i] - from_end[i]) == 0)
            {
                continue;
            }
            else{
                valid = false;
                break;
            }
        }

        if (valid)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}