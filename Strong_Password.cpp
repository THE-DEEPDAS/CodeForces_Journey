// we have to insert a letter anywhere
// time for 1st char = 2s and for others if it is same as previous then 1s else 2s
// we need to make maximum time possible
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        string s;
        cin >> s;

        ll n = s.size(), position = -1;
        string chars;
        for(ll i = 0; i < n; i++){
            if(s[i] != s[i + 1]){
                position = i + 1;
                chars[0] = s[i];
                chars[1] = s[i + 1];
                break;
            }
        }

        bool inserted = false;
        for(char ch = 'a'; ch < 'z'; ch++){
            if(chars.find(ch) == string::npos){
                chars.insert(chars.begin() + position, ch);
                inserted = true;
                break;
            }
        }
        if(!inserted){
            char insert_char = (s.size() == 0) ? 'a' : (s[0] == 'z' ? 'a' : s[0] + 1);
            s.insert(s.begin() + 1 , insert_char);
        }
    }
}