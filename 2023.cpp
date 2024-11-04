// we have a sequence a, whose product was 2023
// k numbers are removed and we now have a sequence B on length n
// from b find a and the elements removed from it
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    vector<ll> factors = {1, 7, 17, 119, 289, 2023};

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll sized, removed;
        cin >> sized >> removed;

        vector<ll> a(sized);
        ll current_product = 1;
        for (ll i = 0; i < sized; i++){
            cin >> a[i];
            current_product *= a[i];
        }

        if(2023 % current_product == 0){
            cout << "YES" << endl;
            cout << 2023 / current_product << " ";
            for (ll i = 0; i < removed - 1; i++){
                cout << 1 << " ";
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}