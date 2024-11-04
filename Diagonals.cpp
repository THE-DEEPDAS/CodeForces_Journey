// we need to find minimum number of diagonal occupied in the n * n board 
// we need to occupy k places 
// (i , j) are on same diagonal if i + j value is same of all the points
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, k;
        cin >> n >> k;

        ll count = 0;
        // we have diagonal sums from 1 to (2 * n - 1)
        // for sum = n , we have n - 1 possiblities
        // for everything else we have n + 1 possiblities
        if(k > 0){
            k -= (n);
            n--;
            count++;
        }

        while(n >= 0 && k > 0){
            k -= (n);
            count++;

            if(k > 0){
                k -= (n);
                count++;
            }
            n--;
        }
        cout << count << endl;
    }
}