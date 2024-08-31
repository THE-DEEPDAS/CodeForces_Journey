// we need a , b , c from l to r who have gcd = 1 when made pairs and remove those 3
// find max number of operations we can perform
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll l, r;
        cin >> l >> r; 
        
        // as even is just a wastage and doesn't help in gcd of 4 consecutive
        if(l % 2 == 0){
            l++;
        }

        // as in l , l + 1, l + 2, l + 3 you will find a triplet satisfying
        cout << (r - l + 2) / 4 << endl;
    }
}