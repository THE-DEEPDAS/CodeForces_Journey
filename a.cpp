#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        ll range = 2;
        ll copy = n;
        while(n - range >= 0){
            n -= range;
            range += 2;
        }
        cout << copy + range / 2 << endl;
    }
}
