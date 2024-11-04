// array is good if i % 2 == a[i] % 2
// use 0 based indexing
// in one move we can swap 2 positions
// find min number of moves to make array good or conclude it is not possible to make it good
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
        cin >> n;
        ll z_size = 0, o_size = 0;
        vector<ll> a(n);
        vector<ll> one_index_problem;
        vector<ll> zero_index_problem;

        for(ll i = 0; i < n; i++){
            cin >> a[i];

            // start checking here only
            if((i % 2) != (a[i] % 2)){
                if(i % 2 == 0){
                    zero_index_problem.push_back(i);
                    z_size++;
                }
                else {
                    one_index_problem.push_back(i);
                    o_size++;
                }
            }
        }

        if(z_size == o_size){
            cout << z_size << endl;
        }
        else cout << -1 << endl;
    }
}