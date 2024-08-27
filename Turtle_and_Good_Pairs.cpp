// we have to find a substring such that we have 2 same chars and between them a non-same charachter
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        string result;
        while (true)
        {
            bool added = false;
            for (int i = 0; i < 26; i++)
            {
                if (freq[i] > 0)
                {
                    result += (char)(i + 'a');
                    freq[i]--;
                    added = true;
                }
            }
            if (!added)
                break; // breaking condition : nothing to add 
        }
        cout << result << endl;
    }
}