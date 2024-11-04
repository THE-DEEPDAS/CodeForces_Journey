// cows has 4 legs and chicken has 2
// find the minimumber number of animals to attain given legs
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll legs;
        cin >> legs;

        if(legs % 4 == 0){
            cout << legs / 4 << endl;
        }
        else{
            cout << (legs / 4) + 1 << endl;
        }
    }
}