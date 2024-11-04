// alice can choose first and last element and remove it
// bob also does the same thing
// last element in array 1 is x and in array 2 is y
// bob wins if x = y else alice wins
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        bool flag = true;

        vector<ll> b(n);
        for (ll i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] != a[i])
                flag = false;
        }
        
        // answer can be bob only if a = b or reverse matches
        if(flag)
            cout << "Bob" << endl;
        else{
            reverse(b.begin(), b.end());
            if(a == b)
                cout << "Bob" << endl;
            else
                cout << "Alice" << endl;
        }
    }
}