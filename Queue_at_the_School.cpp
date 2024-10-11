// so in a line boys and girls are standing randomly
// at any time if a boy is ahead of girl then after 1 second he moves 1 position back
// find how queue looks at time t
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, t;
    cin >> n >> t;    
    string s;
    cin >> s;         

    while (t--) {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++;  // Skip the next position since we just swapped
            }
        }
    }

    cout << s << endl;
}
