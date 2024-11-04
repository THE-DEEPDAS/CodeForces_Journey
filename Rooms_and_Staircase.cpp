// 2 storeyed house has n rooms from 1 to n , left to right
// input has test cases then number of rooms and a string representing stairs with 1
// output max rooms he can visit if he doesn't come to one room 2 times
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;
    for (int testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        string s;
        cin >> n >> s;

        ll ones = 0;
        for (char ch : s)
        {
            if (ch == '1')
                ones++;
        }

        if (ones == 0)
        {
            cout << n << endl;
        }
        else if(ones == 1){
            if(s[0] == '1' || s[n - 1] == '1'){
                cout << 2 * n << endl;
            }
            else{
                cout << 2 * ones + (n - ones) << endl;
            }
        }
        else if (ones == n || ones == n - 1)
        {
            cout << 2 * n << endl;
        }
        else
        {
            cout << 2 * ones + (n - ones) << endl;
        }
    }
}