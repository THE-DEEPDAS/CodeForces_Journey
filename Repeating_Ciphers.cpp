// if S has s1,s2 to sm charachters then sm will be written m times
// i have to decrypt the cipher
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;

    string answer = "";
    int factor = 1;  // Start factor from 1
    int index = 0;   // Start index from 0

    while (index < s.size()) {
        answer += s[index];
        index += factor;
        factor++;
    }

    cout << answer << endl;
}
