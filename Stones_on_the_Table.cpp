// we have n stones, each can be of red / green / blue
// count min stones to be taken so neighbouring are different
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            count++;
        }
    }

    cout << count;
}