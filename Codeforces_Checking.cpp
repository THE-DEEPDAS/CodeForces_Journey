// check if the given char appears in the string "codeforces"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    while(n--) {
        char c;
        cin >> c;
        if(c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'f' || c == 'r' || c == 's') {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
}