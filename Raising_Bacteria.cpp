// each day we put some bacteria in a box and at night it splits into 2 parts
// we want to see x bacteria on a particular day
// initially box was empty
// find min number of bacteria to be put across the days
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x;
    cin >> x;

    ll lower_bound = 1;
    while(lower_bound <= x){
        lower_bound *= 2;
    }
    cout << 1 + x - (lower_bound / 2) << endl;
}