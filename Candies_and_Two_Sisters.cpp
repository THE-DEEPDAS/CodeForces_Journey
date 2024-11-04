// we need to divide n candies into 2 sisters such that both gets atleast 1 candy
// also sum of candies given to both  = n
// also first one should have more candies then second one
// task is to find out number of ways to divide candies
// so a + b = n has how many possiblities is what we try to find
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;
        
        cout << (n - 1) / 2 << endl;
    }
}