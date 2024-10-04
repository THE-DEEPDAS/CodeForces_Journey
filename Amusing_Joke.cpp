// we need to make string 1 and string 2 from 3 , just check if it is possible
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    if(s1.length() + s2.length() != s3.length()) {
        cout << "NO" << endl;
        return 0;
    }

    unordered_map<char, ll> m;
    for(char c : s1) {
        m[c]++;
    }
    for(char c : s2) {
        m[c]++;
    }
    for(char c : s3) {
        m[c]--;
        if(m[c] < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
