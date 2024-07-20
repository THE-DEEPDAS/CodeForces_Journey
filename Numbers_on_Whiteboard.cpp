// 1 to n numbers are written on white board
// now we want to delete 2 numbers a and b and replace it with (a+b)/2
// print the least possible number after n-1 operations and then all the number pairs
// we have replaced
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long testcases = 0;
    cin >> testcases;

    for (int testcase = 0; testcase < testcases; testcase++)
    {
        int n;
        cin >> n;
        int i = n;

        if (n & 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;

        vector<pair<int, int>> pairs;

        while (n > 2)
        {
            int a = n;
            int b = n - 2;

            pairs.push_back({b, a});

            int replacable = (a + b) / 2;

            // If n > 2, set n to n-1 and use the replacable value as the second element.
            if (n > 2)
            {
                pairs.push_back({replacable, n - 1});
            }

            // Decrease n by 1
            n -= 1;
        }

        // Print all pairs
        for (auto &p : pairs)
        {
            if(i > 1){
                cout << p.first << " " << p.second << endl;
                i--;
            }
        }
    }
}