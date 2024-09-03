// in a permutation of n numbers select index from 2 to n - 1 such that
// ai -1 < ai and ai > ai + 1 , swap(ai , ai + 1)
// is it possible to sort the permutations
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // as 1 to n numbers should be there in a permutation
        // now if 1st element is not 1 then we can't change it as swap is not possible there
        // all others can be brought to their respective correct position
        // so check only 1st digit
        if(a[0] == 1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}