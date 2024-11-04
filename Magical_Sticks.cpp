// there are n sticks and for every stick, its length is i where 1 <= i <= n
// now if 2 sticks are joined of length a and b then you get new stick of length a + b and remove those twp
// make max possible sticks of same length
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        // if n = 15
        // 7 + 8 , 9 + 6, 10 + 5, 11 + 4, 12 + 3, 13 + 2 , 14 + 1.
        // if n = 20
        // 9 + 11, 8 + 12, 7 + 13, 6 + 14, 5 + 15, 4 + 16, 3 + 17, 2 + 18, 1 + 19, 20 itself. 
        // if n = 21
        // 10 + 11, 9 + 12, 8 + 13, 7 + 14, 6 + 15, 5 + 16, 4 + 17, 3 + 18, 2 + 19, 1 + 20, 21 itself.
        // if n = 5,
        // 2 + 3, 1 + 4, 5 itself.
        // if n = 9,
        // 4 + 5, 3 + 6, 2 + 7, 1 + 8, 9 itself.
        // if n = 11,
        // 5 + 6, 4 + 7, 3 + 8, 2 + 9, 1 + 10, 11 itself.
        if(n & 1){
            cout << n / 2 + 1 << endl;
        }
        else{
            cout << n / 2 << endl;
        }
    }
}